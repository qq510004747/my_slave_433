/**
******************************************************************************
* @file    		httputil.c
* @author  		WIZnet Software Team
* @version 		V1.0
* @date    	    2015-02-14
* @brief   	  	http中需要的实用函数
******************************************************************************
*/
#include "./E2PROM_Task/E2PROM_Task.h"
#include "httputil.h"
#include "webpge.h"

#define DEBUG_HTTP

extern CONFIG_MSG  ConfigMsg;
extern char tx_buf[MAX_URI_SIZE];
extern char rx_buf[MAX_URI_SIZE];
extern uint8_t ReBoot_Flag;

uint8_t HttpRoboot = FALSE;
uint8_t boundary[64];
uint8_t tmp_buf[1460]= {0xff,};
extern uint8_t pub_buf[1024];

static u16 PwrVin(u16 data);
static u16 Intnet_Port(u8 *str);
static void Save_config_to_eeprom(CONFIG_MSG NetConfigMsg,u8 *str);

/**
*@brief		将基本的配置信息设置到json_callback
*@param		无
*@return	无
*/
static void make_basic_config_setting_json_callback(char* buf, CONFIG_MSG config_msg)
{
    short int temp = (Device.WSDStatus[2]<<8) + Device.WSDStatus[3];
//	u16 hum  = (Device.WSDStatus[6]<<8) + Device.WSDStatus[7];

    unsigned char devsbuf[] = {"已注销"};
	unsigned char netsbuf[] = {"网络异常"};
	unsigned char gprsbuf[] = {"GPRS网络异常"};
	unsigned char gpsbuf[]  = {"GPS获取失败"};
	unsigned char gmsbuf[]  = {"打开"};
    unsigned char watersbuf[] = {"浸水"};
	unsigned char ch1sbuf[] = {"异常"};
	unsigned char ch2sbuf[] = {"正常"};
	unsigned char tdsbuf[]  = {"关闭"};
	unsigned char cssbuf[]  = {"关闭"};
	unsigned char tusbuf[]  = {"关闭"};
	unsigned char jssbuf[]  = {"关闭"};
	unsigned char chzsbuf[] = {"通信故障"};
	
	unsigned char pwrsbuf[] = {"注销"};
	unsigned char pwrCH1buf[] = {"关闭    "};
	unsigned char pwrCH2buf[] = {"关闭    "};
	unsigned char pwrCH3buf[] = {"关闭    "};
	unsigned char pwrCH4buf[] = {"关闭    "};
	unsigned char pwrCH5buf[] = {"关闭    "};
	unsigned char pwrCH6buf[] = {"关闭    "};
	
	if(DeviceStatus.Enable == TRUE)  memcpy(devsbuf,"已启用", sizeof(devsbuf));//
	if(DeviceStatus.Internet != Err) memcpy(netsbuf,"网络正常",sizeof(netsbuf));//
	if(DeviceStatus.GPRS != Err)     memcpy(gprsbuf,"网络正常",sizeof(netsbuf));//
	if(DeviceStatus.AGPS != Err)     memcpy(gpsbuf,"获取成功",sizeof(netsbuf));//
	if(Device.WSDStatus[1]  != 0x00 ) temp = ~temp;
	if(Device.PutInStatus[0][0] == 0x11)   memcpy(gmsbuf,"关闭",sizeof(gmsbuf)); //
	if(Device.WSDStatus[8]   == 0x30)      memcpy(watersbuf,"正常",sizeof(watersbuf)); //
	if(Device.PutInStatus[1][0] == 0x21)   memcpy(ch1sbuf,"正常",sizeof(ch1sbuf)); //
	if(Device.PutInStatus[2][0] == 0x31)   memcpy(ch2sbuf,"正常",sizeof(ch2sbuf)); //
	if(Device.PutOutStatus[0][0]== 0x11)   memcpy(tdsbuf,"开启",sizeof(tdsbuf)); //
	if(Device.PutOutStatus[1][0] == 0x21)  memcpy(cssbuf,"开启",sizeof(cssbuf)); //
	if(Device.PutOutStatus[2][0] == 0x31)  memcpy(tusbuf,"开启",sizeof(tusbuf)); //
	if(Device.PutOutStatus[3][0] == 0x41)  memcpy(jssbuf,"开启",sizeof(jssbuf)); //
	if(Device.PutOutStatus[3][0] == 0x41)  memcpy(jssbuf,"开启",sizeof(jssbuf)); //
	if(Device.CHZStatus[0] == 0x01)        memcpy(chzsbuf,"开启",sizeof(jssbuf)); //
	else if(Device.CHZStatus[0] == 0x00)   memcpy(chzsbuf,"关闭",sizeof(jssbuf)); //
	
	if(DeviceStatus.PwrEnable == TRUE)     memcpy(pwrsbuf,"启用",sizeof(pwrsbuf)); //
	if(Device.PwrStatus[0][0] == 0x11)     memcpy(pwrCH1buf,"开启    ",sizeof(pwrCH1buf)); //
	if(Device.PwrStatus[1][0] == 0x21)     memcpy(pwrCH2buf,"开启    ",sizeof(pwrCH1buf)); //
	if(Device.PwrStatus[2][0] == 0x31)     memcpy(pwrCH3buf,"开启    ",sizeof(pwrCH1buf)); //
	if(Device.PwrStatus[3][0] == 0x41)     memcpy(pwrCH4buf,"开启    ",sizeof(pwrCH1buf)); //
	if(Device.PwrStatus[4][0] == 0x51)     memcpy(pwrCH5buf,"开启    ",sizeof(pwrCH1buf)); //
	if(Device.PwrStatus[5][0] == 0x61)     memcpy(pwrCH6buf,"开启    ",sizeof(pwrCH1buf)); //
	
    if(DeviceStatus.AdminHttp == TRUE) //已登录
    {
	   sprintf(buf,"settingsCallback({\"ver\":\"%d.%d\",\
									 \"mac\":\"%02X:%02X:%02X:%02X:%02X:%02X\",\
									 \"ip\":\"%d.%d.%d.%d\",\
									 \"gw\":\"%d.%d.%d.%d\",\
									 \"sub\":\"%d.%d.%d.%d\",\
									 \"port\":\"%d\",\
	                                 \"Rip\":\"%d.%d.%d.%d\",\
									 \"Rport\":\"%d\",\
									 \"Gip\":\"%d.%d.%d.%d\",\
									 \"Gport\":\"%d\",\
	                                 \"Derstatus\":\"%s\",\
								     \"Netstatus\":\"%s\",\
								     \"GPRSstatus\":\"%s\",\
								     \"GPSstatus\":\"%s\",\
								     \"Temp\":\"%d.%d%s\",\
	                                 \"Humidity\":\"%d.%d%s\",\
	                                 \"Gmstatus\":\"%s\",\
	                                 \"Waterstatus\":\"%s\",\
	                                 \"CH1status\":\"%s\",\
	                                 \"CH2status\":\"%s\",\
	                                 \"TDKG\":\"%s\",\
									 \"CSKG\":\"%s\",\
									 \"TUKG\":\"%s\",\
									 \"JSKG\":\"%s\",\
									 \"CHZstatus\":\"%s\",\
									 \"CHZvin\":\"%d%s\",\
									 \"CHZcur\":\"%d.%d%s\",\
									 \"CHZleak\":\"%d%s\",\
									 \"Pwrstatus\":\"%s\",\
									 \"PwrCH1S\":\"%s%d%s%d%s\",\
									 \"PwrCH2S\":\"%s%d%s%d%s\",\
									 \"PwrCH3S\":\"%s\",\
									 \"PwrCH4S\":\"%s\",\
									 \"PwrCH5S\":\"%s\",\
									 \"PwrCH6S\":\"%s\"});",
				config_msg.sw_ver[0],config_msg.sw_ver[1],
				config_msg.mac[0],config_msg.mac[1],config_msg.mac[2],config_msg.mac[3],config_msg.mac[4],config_msg.mac[5],
				config_msg.lip[0],config_msg.lip[1],config_msg.lip[2],config_msg.lip[3],
				config_msg.gw[0],config_msg.gw[1],config_msg.gw[2],config_msg.gw[3],
				config_msg.sub[0],config_msg.sub[1],config_msg.sub[2],config_msg.sub[3],
				ConfigMsg.port,
				config_msg.serip[0],config_msg.serip[1],config_msg.serip[2],config_msg.serip[3],
				ConfigMsg.serport,
	            config_msg.gprsip[0],config_msg.gprsip[1],config_msg.gprsip[2],config_msg.gprsip[3],
				ConfigMsg.gprsport,
				devsbuf,//设备状态
				netsbuf,//网络状态
				gprsbuf,//GPRS状态
				gpsbuf,//GPS状态
				temp/10,abs((~temp)%10),"℃",//设备温度
				((Device.WSDStatus[6]<<8) + Device.WSDStatus[7])/10,((Device.WSDStatus[6]<<8) + Device.WSDStatus[7])%10,"%", //设备湿度
				gmsbuf,//柜门状态
				watersbuf,//浸水状态
				ch1sbuf,
				ch2sbuf,
				tdsbuf,
				cssbuf,
				tusbuf,
				jssbuf,
				chzsbuf,
				((Device.CHZStatus[4]<<8)+Device.CHZStatus[5])/10,"V",//电压
				((Device.CHZStatus[8]<<8)+Device.CHZStatus[9])/10,((Device.CHZStatus[8]<<8)+Device.CHZStatus[9])%10,"A",//电流
				((Device.CHZStatus[12]<<8)+Device.CHZStatus[13])/10,"mA",//漏电
				pwrsbuf,
				pwrCH1buf,
                PwrVin((Device.PwrStatus[0][4]<<8) +Device.PwrStatus[0][5]),"V  ",
				PwrVin((Device.PwrStatus[0][8]<<8) +Device.PwrStatus[0][9]),"A  ",
				pwrCH2buf,
                PwrVin((Device.PwrStatus[1][4]<<8) +Device.PwrStatus[1][5]),"V  ",
				PwrVin((Device.PwrStatus[1][8]<<8) +Device.PwrStatus[1][9]),"A  ",
				pwrCH3buf,
                pwrCH4buf,
                pwrCH5buf,
                pwrCH6buf
			   );
   }else //没有登录
   {
//      sprintf(buf,"settingsCallback({\"admin\":\"%s\",\
//									 \"password\":\"%s\"});",
//				"用户名","密码"
//			  ); //使用placeholder
   }
}

/**
*@brief		完成http响应
*@param		无
*@return	无
*/
void HttpServer(void)
{
    uint8_t ch=SOCK_HTTPS;								/*定义一个socket*/
    uint16_t len;

    st_http_request *http_request;						/*定义一个结构指针*/
    memset(rx_buf,0x00,MAX_URI_SIZE);
    http_request = (st_http_request*)rx_buf;
    /* http service start */
    switch(getSn_SR(ch))								/*获取socket状态*/
    {
    case SOCK_INIT:									/*socket处于初始化状态*/
        listen(ch);
        break;

    case SOCK_LISTEN:								  /*socket处于监听状态*/
        break;

    case SOCK_ESTABLISHED:							   /*socket处于连接状态*/
        if(getSn_IR(ch) & Sn_IR_CON)
        {
            setSn_IR(ch, Sn_IR_CON);				    /*清除中断标志位*/
        }
        if ((len = getSn_RX_RSR(ch)) > 0)
        {
            len = recv(ch, (uint8_t*)http_request, len); /*接收http请求*/
            *(((uint8_t*)http_request)+len) = 0;
            proc_http(ch, (uint8_t*)http_request);		/*接收http请求并发送http响应*/
            disconnect(ch);
        }
        break;

    case SOCK_CLOSE_WAIT:   											/*socket处于等待关闭状态*/
        if ((len = getSn_RX_RSR(ch)) > 0)
        {
            len = recv(ch, (uint8_t*)http_request, len);				/*接收http请求*/
            *(((uint8_t*)http_request)+len) = 0;
            proc_http(ch, (uint8_t*)http_request);						/*接收http请求并发送http响应*/
        }
        disconnect(ch);
        break;

    case SOCK_CLOSED:                   									/*socket处于关闭状态*/
        socket(ch, Sn_MR_TCP, 80, 0x00);   									/*打开socket*/
        break;

    default:
        break;
    }
}

/**
*@brief		接收http请求报文并发送http响应
*@param		s: http服务器socket
*@param		buf：解析报文内容
*@return	无
*/
void proc_http(SOCKET s, uint8_t * buf)
{
    char* name;
    char req_name[32]= {0x00,};		/*定义一个http响应报文的指针*/
    unsigned long file_len=0;		/*定义http请求报文头的结构体指针*/
    uint16_t send_len=0;
    uint8_t* http_response;
    st_http_request *http_request;
    memset(tx_buf,0x00,MAX_URI_SIZE);
    http_response = (uint8_t*)rx_buf;
    http_request = (st_http_request*)tx_buf;
    parse_http_request(http_request, buf);    	/*解析http请求报文头*/

    switch (http_request->METHOD)
    {
    case METHOD_ERR :																			/*请求报文头错误*/
        memcpy(http_response, ERROR_REQUEST_PAGE, sizeof(ERROR_REQUEST_PAGE));
        send(s, (uint8_t *)http_response, strlen((char const*)http_response));
        break;

    case METHOD_HEAD:																			/*HEAD请求方式*/

    case METHOD_GET:																			/*GET请求方式*/
        name = http_request->URI;
        if(strcmp(name,"/index.htm")==0 || strcmp(name,"/")==0 || (strcmp(name,"/index.html")==0))
        {
            if(DeviceStatus.AdminHttp == TRUE) //已登录
  			   file_len = strlen(INDEX_HTML);
			else
			   file_len = strlen(Admin_HTML);
            make_http_response_head((uint8_t*)http_response, PTYPE_HTML,file_len);
            send(s,http_response,strlen((char const*)http_response));
            send_len=0;
            while(file_len)
            {
                if(file_len>1024)
                {
                    if(getSn_SR(s)!=SOCK_ESTABLISHED)
                    {
                        return;
                    }
					if(DeviceStatus.AdminHttp == TRUE) //已登录
                      send(s, (uint8_t *)INDEX_HTML+send_len, 1024);
					else
					  send(s, (uint8_t *)Admin_HTML+send_len, 1024);
                    send_len+=1024;
                    file_len-=1024;
                }else
                {
					if(DeviceStatus.AdminHttp == TRUE) //已登录
                       send(s, (uint8_t *)INDEX_HTML+send_len, file_len);
					else
					   send(s, (uint8_t *)Admin_HTML+send_len, file_len);
                    send_len+=file_len;
                    file_len-=file_len;
                }
            }
        }else if(strcmp(name,"/w5500.js")==0)
        {
            memset(tx_buf,0,MAX_URI_SIZE);
            make_basic_config_setting_json_callback(tx_buf,ConfigMsg);
            sprintf((char *)http_response,"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length:%d\r\n\r\n%s",strlen(tx_buf),tx_buf);
            send(s, (unsigned char *)http_response, strlen((char const*)http_response));
        }
        break;
    case METHOD_POST:	/*POST请求*/
        mid(http_request->URI, "/", " ", req_name);	/*获取该请求的文件名*/
        if(strcmp(req_name,"config.cgi")==0)
        { 					
            if(DeviceStatus.AdminHttp == TRUE) //已登录
			{
				cgi_ipconfig(http_request);	/*将配置信息写进单片机eeprom*/
				make_cgi_response(10,(char*)ConfigMsg.lip,tx_buf);	/*生成响应的文本部分*/
				sprintf((char *)http_response,"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length:%d\r\n\r\n%s",strlen(tx_buf),tx_buf);
				/*发送http响应*/
				send(s, (unsigned char *)http_response, strlen((char *)http_response));
			}else
			{
			    cgi_ipconfig(http_request);	/*将配置信息写进单片机eeprom*/
				make_cgi_response(3,(char*)ConfigMsg.lip,tx_buf);	/*生成响应的文本部分*/
				sprintf((char *)http_response,"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length:%d\r\n\r\n%s",strlen(tx_buf),tx_buf);
				/*发送http响应*/
				send(s, (unsigned char *)http_response, strlen((char *)http_response));
			}
            disconnect(s);										/*断开socket连接*/
            if((HttpRoboot == TRUE)&&(DeviceStatus.AdminHttp == TRUE)) 
				ReBoot_Flag = TRUE;			/*重启标志位置1*/
			else HttpRoboot =FALSE;
            return;
        }
	
        break;

    default :
        break;
    }
}

/**
*@brief		将配置信息写进单片机eeprom
*@param		http_request：定义一个http请求的结构体指针
*@return	无
*/
void cgi_ipconfig(st_http_request *http_request)
{
    uint8_t  i;
	uint8_t  *param;
	uint32_t port =0;
	uint8_t  adminbuff[12];
	CONFIG_MSG  NetConfigMsg;
	if(DeviceStatus.AdminHttp == TRUE) //已登录
	{
		param = get_http_param_value(http_request->URI,"ip");		/*获取修改后的IP地址*/
		if(param)
		{
			inet_addr_((uint8_t*)param, NetConfigMsg.lip);
		}
		param = get_http_param_value(http_request->URI,"gw");		/*获取修改后的网关*/
		if(param)
		{
			inet_addr_((uint8_t*)param, NetConfigMsg.gw);
		}
		param = get_http_param_value(http_request->URI,"sub");	/*获取修改后的子网掩码*/
		if(param)
		{
			inet_addr_((uint8_t*)param, NetConfigMsg.sub);
		}
		param = get_http_param_value(http_request->URI,"port");	/*获取修改后的端口号*/
		if(param)
		{
			for(i=0;i<5;i++) adminbuff[i] = *(param+i);	
			port = Intnet_Port(adminbuff); 
			if(port>0) NetConfigMsg.port = Intnet_Port(adminbuff);
			else   NetConfigMsg.port = ConfigMsg.port; 
		}
		param = get_http_param_value(http_request->URI,"Rip");	/*获取修改后的服务器IP*/
		if(param)
		{
			inet_addr_((uint8_t*)param, NetConfigMsg.serip);
		}
		param = get_http_param_value(http_request->URI,"Rport");	/*获取修改后的服务器端口号*/
		if(param)
		{
			for(i=0;i<5;i++) adminbuff[i] = *(param+i);	
			port = Intnet_Port(adminbuff); 
			if(port>0)  NetConfigMsg.serport = Intnet_Port(adminbuff); 
            else NetConfigMsg.serport = ConfigMsg.serport;			
		}param = get_http_param_value(http_request->URI,"Gip");	/*获取修改后的GPRS服务器IP*/
		if(param)
		{
			inet_addr_((uint8_t*)param, NetConfigMsg.gprsip);
		}
		param = get_http_param_value(http_request->URI,"Gport");	/*获取修改后的GPRS服务器端口号*/
		if(param)
		{
			for(i=0;i<5;i++) adminbuff[i] = *(param+i);	
			port = Intnet_Port(adminbuff); 
			if(port>0) NetConfigMsg.gprsport = Intnet_Port(adminbuff); 
            else 	NetConfigMsg.gprsport =	ConfigMsg.gprsport;	
		}
	   for(i=0;i<12;i++) adminbuff[i] = 0;
	   param = get_http_param_value(http_request->URI,"admin");		/*获取修改后的IP地址*/
	   if(param)
	   {
	      for(i=0;i<6;i++)
		   adminbuff[i] = *(param+i);
	   }
	   param = get_http_param_value(http_request->URI,"password");	/*获取修改后的IP地址*/
	   if(param)
	   {
	      for(i=0;i<6;i++)
		   adminbuff[i+6] = *(param+i);
	   }	
       Save_config_to_eeprom(NetConfigMsg,adminbuff);			/*将获取的网络参数写进eeprom*/	
	   HttpRoboot = TRUE;  //系统重启辅助标志
	}else
	{
	   param = get_http_param_value(http_request->URI,"admin");		/*获取修改后的IP地址*/
	   if(param)
	   {
	      for(i=0;i<6;i++)
		   adminbuff[i] = *(param+i);
	   }
	   param = get_http_param_value(http_request->URI,"password");	/*获取修改后的IP地址*/
	   if(param)
	   {
	      for(i=0;i<6;i++)
		   adminbuff[i+6] = *(param+i);
	   }
	   if(StrCmp(Device.Admin,adminbuff,12) == TRUE)
	        DeviceStatus.AdminHttp  = TRUE; 
	   else DeviceStatus.AdminHttp = FALSE;
	}
}

/**
*@brief		执行http响应
*@param		无
*@return	无
*/
void make_cgi_response(uint16_t delay, char* url,char* cgi_response_buf)
{
    sprintf(cgi_response_buf,"<html><head><title>iWeb - Configuration</title><script language=javascript>j=%d;function func(){document.getElementById('delay').innerText=' '+j + ' ';j--;setTimeout('func()',1000);if(j==0)location.href='http://%d.%d.%d.%d/';}</script></head><body onload='func()'>please wait for a while, the module will boot in<span style='color:red;' id='delay'></span> seconds.</body></html>",delay,url[0],url[1],url[2],url[3]);
    return;
}

/**
*@brief		执行http响应
*@param	    实现功能：1.设备IP全部为0.0.0.0时，默认是错误的，页面配置的参数都不修改的
                      2.用户名数据全部为0时，默认是错误的，页面配置的参数都不修改的
*@return	无
*/
static void Save_config_to_eeprom(CONFIG_MSG  NetConfigMsg,u8 *str)
{
    u8 admin =0;
	u8 datatemp[40]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
    for(u8 i=0;i<4;i++) //设备IP
	{
		if(NetConfigMsg.lip[i] > 0) 
		{   //设备网络参数
		    memcpy(datatemp,NetConfigMsg.lip, 4); 
			memcpy(datatemp+4,NetConfigMsg.sub, 4);
			memcpy(datatemp+8,NetConfigMsg.gw, 4); 
			memcpy(datatemp+12,NetConfigMsg.dns, 4);
			datatemp[16] = NetConfigMsg.port>>8;
			datatemp[17] = NetConfigMsg.port&0xFF;
			datatemp[18] = 0xAA;
			datatemp[19] = 0x55;
			
			//服务器网络参数
			memcpy(datatemp+20,NetConfigMsg.serip, 4); 
			datatemp[24] = NetConfigMsg.serport>>8;
			datatemp[25] = NetConfigMsg.serport&0xFF;
			datatemp[26] = 0xAA;
			datatemp[27] = 0x55;
			//GPRS服务器网络参数
			memcpy(datatemp+28,NetConfigMsg.gprsip,4); 
			datatemp[32] = NetConfigMsg.gprsport>>8;
			datatemp[33] = NetConfigMsg.gprsport&0xFF;
			datatemp[34] = 0xAA;
			datatemp[35] = 0x55;			
			Save_NetMsg_E2PROM(NetMsgPage,datatemp,40);	
			//用户名
			for(u8 i=0;i<12;i++) 
			{
			  if(((*(str+i) >='0')&&(*(str+i)<= '9')) ||((*(str+i) >='A')&&(*(str+i) <='Z')) ||((*(str+i) >='a')&&(*(str+i) <='z')))
			  {
				 admin++;
			  }	  	   
			}
			if(admin == 12) Save_NetMsg_E2PROM(AdminMsgaddr,str,NetAdminPassWorsLen); 
			break;
		}
	}
}

//
static u16 Intnet_Port(u8 *str)
{
	u32 port = FALSE;
	if((*(str+4)>= '0')&&(*(str+4) <= '9')) //50000
	{
	  port += *(str+4) -'0';
	  if((*(str+3)>= '0')&&(*(str+3) <= '9'))
	  {
	     port += (*(str+3) -'0')*10;
		 if((*(str+2)>= '0')&&(*(str+2) <= '9'))
		 {
		     port += (*(str+2) -'0')*100;
			 if((*(str+1)>= '0')&&(*(str+1) <= '9'))
		     {
			   port += (*(str+1) -'0')*1000;
			   if((*(str)>= '0')&&(*(str) <= '9'))
			   {
				   port += (*(str) -'0')*10000;
			   }else return FALSE;
			 }else return FALSE;
		 }else return FALSE;	 	 
	  }else return FALSE;
	}else if((*(str+3)>= '0')&&(*(str+3) <= '9'))
	{
	     port += (*(str+3) -'0');
		 if((*(str+2)>= '0')&&(*(str+2) <= '9'))
		 {
		     port += (*(str+2) -'0')*10;
			 if((*(str+1)>= '0')&&(*(str+1) <= '9'))
		     {
			   port += (*(str+1) -'0')*100;
			   if((*(str)>= '0')&&(*(str) <= '9'))
			   {
				   port += (*(str) -'0')*1000;
			   }else return FALSE;
			 }else return FALSE;
		 }else return FALSE;	 	 
	}else if((*(str+2)>= '0')&&(*(str+2) <= '9'))
	{
		 port += (*(str+2) -'0');
		 if((*(str+1)>= '0')&&(*(str+1) <= '9'))
		 {
		   port += (*(str+1) -'0')*10;
		   if((*(str)>= '0')&&(*(str) <= '9'))
		   {
			   port += (*(str) -'0')*100;
		   }else return FALSE;
		 }else return FALSE;
	}else if((*(str+1)>= '0')&&(*(str+1) <= '9'))
	{
	   port += (*(str+1) -'0');
	   if((*(str)>= '0')&&(*(str) <= '9'))
	   {
		   port += (*(str) -'0')*10; 
	   }else return FALSE;
	}else if((*(str)>= '0')&&(*(str) <= '9'))
    {
	   port += (*(str) -'0');  
    }else return FALSE;
   
    if(port<=0xFFFF)  return port&0xFFFF;
	else return FALSE;
}

//电源电压显示限制
static u16 PwrVin(u16 data)
{
  if( data>= 4000) return 0;
	else return data/10;

}







