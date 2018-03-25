/**
******************************************************************************
* @file    			DNS.c
* @author  			WIZnet Software Team 
* @version 			V1.0
* @date    			2015-02-14
* @brief   			域名解析客户端函数 通过解析域名Domain_name可获得其IP地址  
******************************************************************************
*/

#include "W5500.h"
#include "W5500_socket.h"

#include "W5500_conf.h"
#include "DNS.h"

uint8_t domain_name[]="www.baidu.cn";
uint8_t dns_get_ip[4];
uint16_t MSG_ID = 0x1122;
uint8_t  BUFPUB[1024];

/**
*@brief		 生成DNS查询报文
*@param		 op   - 期望的数据
*@param		 name - 指向域名的指针
*@param		 buf  - 接收DNS信息的
*@param		 len  - buf的长度
*@return	 返回DNS报文指针
*/
int dns_makequery(uint16_t op, uint8_t * name, uint8_t * buf, uint16_t len)
{
  uint8_t  *cp;
  uint8_t  *cp1;
  uint8_t  *dname;
  uint16_t p;
  uint16_t dlen;
  
  cp = buf;
  
  MSG_ID++;
  *(uint16_t*)&cp[0] = htons(MSG_ID);
  p = (op << 11) | 0x0100;
  *(uint16_t*)&cp[2] = htons(p);
  *(uint16_t*)&cp[4] = htons(1);
  *(uint16_t*)&cp[6] = htons(0);
  *(uint16_t*)&cp[8] = htons(0);
  *(uint16_t*)&cp[10]= htons(0);
  
  cp += sizeof(uint16_t)*6;
  dname = name;
  dlen = strlen((char*)dname);
  for (;;)
  {
    /* Look for next dot */
    cp1 = (unsigned char*)strchr((char*)dname, '.');
    
    if (cp1) len = cp1 - dname;						/* More to come */
    else len = dlen;								/* Last component */
    
    *cp++ = len;									/* Write length of component */
    if (len == 0) break;
    
    strncpy((char *)cp, (char*)dname, len);			/* Copy component up to (but not including) dot */
    cp += len;
    if (!cp1)
    {
      *cp++ = 0;									/* Last one; write null and finish */
      break;
    }
    dname += len+1;
    dlen -= len+1;
  }
  
  *(uint16_t*)&cp[0] = htons(0x0001);				/* type */
  *(uint16_t*)&cp[2] = htons(0x0001);				/* class */
  cp += sizeof(uint16_t)*2;
  
  return ((int)((uint32_t)(cp) - (uint32_t)(buf)));
}

/**
*@brief		 查询DNS报文信息，解析来自DNS服务器的回复
*@param		 s：DNS服务器socket，name:要解析的信息
*@return	 成功: 返回1, 失败 :返回 -1
*/
uint8_t dns_query(uint8_t s, uint8_t * name)
{
  static uint32_t dns_wait_time = 0;
  struct dhdr dhp;									/*定义一个结构体用来包含报文头信息*/
  uint8_t ip[4];
  uint16_t len, port;
  switch(getSn_SR(s))								/*获取socket状态*/
  {
		case SOCK_CLOSED:
			dns_wait_time = 0;
			socket(s, Sn_MR_UDP, 3000, 0);			/*打开W5500的socket的3000端口，并设置为UDP模式*/
			break;  
		
    case SOCK_UDP:									/*socket已打开*/
			len = dns_makequery(0, name, BUFPUB, MAX_DNS_BUF_SIZE);						/*接收DNS请求报文并存入BUFPUB*/
			sendto(s, BUFPUB, len, EXTERN_DNS_SERVERIP, IPPORT_DOMAIN);					/*发送DNS请求报文给DNS服务器*/
      if ((len = getSn_RX_RSR(s)) > 0)
			{
        if (len > MAX_DNS_BUF_SIZE) len = MAX_DNS_BUF_SIZE;
				len = recvfrom(s, BUFPUB, len, ip, &port);								/*接收UDP传输的数据并存入BUFPUB*/
        if(parseMSG(&dhp, BUFPUB))														/*解析DNS响应信息*/
				{
          close(s);																		/*关闭socket*/
          return DNS_RET_SUCCESS;														/*返回DNS解析成功域名信息*/
				}
        else 
					dns_wait_time = DNS_RESPONSE_TIMEOUT;								/*等待响应时间设置为超时*/
      }
      else
      {
        Delay_ms(1000);																	/*没有收到DNS服务器的UDP回复，避免太频繁，延时1s*/
        dns_wait_time++;																/*DNS响应时间加1*/
      }
      if(dns_wait_time >= DNS_RESPONSE_TIMEOUT)											/*如果DNS等待时间超过3s*/
      {
        close(s);																		/*关闭socket*/
        return DNS_RET_FAIL;
      }
      break;
			
  }
  return DNS_RET_PROGRESS;
}

/**
*@brief		查询DNS报文信息，解析来自DNS服务器的回复
*@param		s：DNS服务器socket，name:要解析的信息
*@return	成功: 返回1, 失败 :返回 -1
*/
void do_dns(void)
{
  uint8_t dns_retry_cnt=0;
  uint8_t dns_ok=0;
  if( (dns_ok==1) || (dns_retry_cnt > DNS_RETRY))
  {
    return;
  }

  else if(memcmp(ConfigMsg.dns,"\x00\x00\x00\x00",4))						/*判断DNS服务器的IP地址是否配置*/
  {
    switch(dns_query(SOCK_DNS,domain_name))									/*发出DNS请求报文和解析DNS响应报文*/
    {
      case DNS_RET_SUCCESS:													/*DNS解析域名成功*/
        dns_ok=1;															/*DNS运行标志位置1*/
        memcpy(ConfigMsg.serip,dns_get_ip,4);									/*把解析到的IP地址复制给ConfigMsg.rip*/
        dns_retry_cnt=0;													/*DNS请求报文次数置0*/
//        printf("Get [%s]'s IP address [%d.%d.%d.%d] from %d.%d.%d.%d\r\n",domain_name,ConfigMsg.serip[0],ConfigMsg.serip[1],ConfigMsg.serip[2],ConfigMsg.serip[3],ConfigMsg.dns[0],ConfigMsg.dns[1],ConfigMsg.dns[2],ConfigMsg.dns[3]);
        break;
			
      case DNS_RET_FAIL:													/*DNS解析域名失败*/
        dns_ok=0;															/*DNS运行标志位置0*/
        dns_retry_cnt++;													/*DNS请求报文次数加1*/
//        printf("Fail! Please check your network configuration or DNS server.\r\n");
        break;
			
      default:
        break;
    }
		
  }
  else	;																	/*如果DNS服务器IP为0.0.0.0*/
//     printf("Invalid DNS server [%d.%d.%d.%d]\r\n",ConfigMsg.dns[0],ConfigMsg.dns[1],ConfigMsg.dns[2],ConfigMsg.dns[3]);
}


/**
*@brief		 将压缩域名信息转化为可读的形式
*@param		 msg        - 指向回复信息的指针
             compressed - 指向回复信息中域名的指针
             buf        - 存放可读的域名信息
             len        - buf的长度
*@return	 返回压缩域名信息长度
*/
int parse_name(uint8_t * msg, uint8_t * compressed, /*char * buf,*/ uint16_t len)
{
  uint16_t slen;															/* Length of current segment */
  uint8_t  * cp;
  int16_t  clen = 0;														/* Total length of compressed name */
  int16_t  indirect = 0;													/* Set if indirection encountered */
  int16_t  nseg = 0;														/* Total number of segments in name */
  int8_t   name[MAX_DNS_BUF_SIZE];
  int8_t   *buf;
  
  buf = name;
  
  cp = compressed;
  
  for (;;)
  {
    slen = *cp++;															/* Length of this segment */
    
    if (!indirect) clen++;
    
    if ((slen & 0xc0) == 0xc0)
    {
      if (!indirect)
        clen++;
      indirect = 1;
      /* Follow indirection */
      cp = &msg[((slen & 0x3f)<<8) + *cp];
      slen = *cp++;
    }
    
    if (slen == 0)															/* zero length == all done */
      break;
    
    len -= slen + 1;
    
    if (len <= 0) return -1;
    
    if (!indirect) clen += slen;
    
    while (slen-- != 0) *buf++ = (char)*cp++;
    *buf++ = '.';
    nseg++;
  }

  if (nseg == 0)                                                    	 /* Root name; represent as single dot */
  {
    *buf++ = '.';
    len--;
  }
  
  *buf++ = '\0';
  len--;
  
  return clen;															/* Length of compressed message */
}

/**
*@brief		 解析回复消息的问询记录
*@param		 msg - 指向回复信息的指针
           cp  - 指向问询记录的指针
*@return	 返回下一个记录指针
*/
uint8_t * dns_question(uint8_t * msg, uint8_t * cp)
{
  int len;
  
  len = parse_name(msg, cp, /*name,*/ MAX_DNS_BUF_SIZE);
  
  if (len == -1) return 0;
  
  cp += len;
  cp += 2;		/* type */
  cp += 2;		/* class */
  
  return cp;
}

/**
*@brief		 解析回复信息的应答记录
*@param		 msg - 指向回复信息的指针
           cp  - 接收应答记录的指针
*@return	 返回下一个应答记录指针
*/
uint8_t * dns_answer(uint8_t * msg, uint8_t * cp)
{
  int len, type;
  
  len = parse_name(msg, cp, /*name,*/ MAX_DNS_BUF_SIZE);
  
  if (len == -1) return 0;
  
  cp += len;
  type = ntohs(*((uint16_t*)&cp[0]));
  cp += 2;		/* type */
  cp += 2;		/* class */
  cp += 4;		/* ttl */
  cp += 2;		/* len */
  
  switch (type)
  {
    case TYPE_A:
      dns_get_ip[0] = *cp++;
      dns_get_ip[1] = *cp++;
      dns_get_ip[2] = *cp++;
      dns_get_ip[3] = *cp++;
      break;
    case TYPE_CNAME:
    case TYPE_MB:
    case TYPE_MG:
    case TYPE_MR:
    case TYPE_NS:
    case TYPE_PTR:
      /* These types all consist of a single domain name */
      /* convert it to ascii format */
      len = parse_name(msg, cp, /*name,*/ MAX_DNS_BUF_SIZE);
      if (len == -1) return 0;
      
      cp += len;
      break;
		
    case TYPE_HINFO:
      len = *cp++;
      cp += len;
      len = *cp++;
      cp += len;
      break;
		
    case TYPE_MX:
      cp += 2;
      /* Get domain name of exchanger */
      len = parse_name(msg, cp,/* name,*/ MAX_DNS_BUF_SIZE);
      if (len == -1) return 0;
      cp += len;
      break;
		
    case TYPE_SOA:
      /* Get domain name of name server */
      len = parse_name(msg, cp,/* name,*/ MAX_DNS_BUF_SIZE);
      if (len == -1) return 0;
      cp += len;
      /* Get domain name of responsible person */
      len = parse_name(msg, cp,/* name,*/ MAX_DNS_BUF_SIZE);
      if (len == -1) return 0;
      
      cp += len;
      
      cp += 4;
      cp += 4;
      cp += 4;
      cp += 4;
      cp += 4;
      break;
		
    case TYPE_TXT:
      /* Just stash */
      break;
		
    default:
    /* Ignore */
      break;
  }
  
  return cp;
}

/**
*@brief		 解析来自DNS服务器的回复报文
*@param		 dhdr - 指向DNS信息头的指针
           buf  - 接收回复信息
           len  - 回复信息的长度
*@return	 无
*/
uint8_t parseMSG(struct dhdr * pdhdr, uint8_t * pbuf)
{
  uint16_t tmp;
  uint16_t i;
  uint8_t * msg;
  uint8_t * cp;
  
  msg = pbuf;
  memset(pdhdr, 0, sizeof(pdhdr));
  
  pdhdr->id = ntohs(*((uint16_t*)&msg[0]));
  tmp = ntohs(*((uint16_t*)&msg[2]));
  if (tmp & 0x8000) pdhdr->qr = 1;
  
  pdhdr->opcode = (tmp >> 11) & 0xf;
  
  if (tmp & 0x0400) pdhdr->aa = 1;
  if (tmp & 0x0200) pdhdr->tc = 1;
  if (tmp & 0x0100) pdhdr->rd = 1;
  if (tmp & 0x0080) pdhdr->ra = 1;
  
  pdhdr->rcode = tmp & 0xf;
  pdhdr->qdcount = ntohs(*((uint16_t*)&msg[4]));
  pdhdr->ancount = ntohs(*((uint16_t*)&msg[6]));
  pdhdr->nscount = ntohs(*((uint16_t*)&msg[8]));
  pdhdr->arcount = ntohs(*((uint16_t*)&msg[10]));
  
  /* Now parse the variable length sections */
  cp = &msg[12]; 
  /* Question section */
  for (i = 0; i < pdhdr->qdcount; i++)
  {
    cp = dns_question(msg, cp);
  } 
  /* Answer section */
  for (i = 0; i < pdhdr->ancount; i++)
  {
    cp = dns_answer(msg, cp);
  }  
  /* Name server (authority) section */
  for (i = 0; i < pdhdr->nscount; i++)
  {
    ;
  }  
  /* Additional section */
  for (i = 0; i < pdhdr->arcount; i++)
  {
    ;
  }
  
  if(pdhdr->rcode == 0) return 1;	
  else return 0;
}


