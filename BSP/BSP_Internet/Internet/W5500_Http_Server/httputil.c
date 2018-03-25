/**
******************************************************************************
* @file    		httputil.c
* @author  		WIZnet Software Team
* @version 		V1.0
* @date    	    2015-02-14
* @brief   	  	http����Ҫ��ʵ�ú���
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
*@brief		��������������Ϣ���õ�json_callback
*@param		��
*@return	��
*/
static void make_basic_config_setting_json_callback(char* buf, CONFIG_MSG config_msg)
{
    short int temp = (Device.WSDStatus[2]<<8) + Device.WSDStatus[3];
//	u16 hum  = (Device.WSDStatus[6]<<8) + Device.WSDStatus[7];

    unsigned char devsbuf[] = {"��ע��"};
	unsigned char netsbuf[] = {"�����쳣"};
	unsigned char gprsbuf[] = {"GPRS�����쳣"};
	unsigned char gpsbuf[]  = {"GPS��ȡʧ��"};
	unsigned char gmsbuf[]  = {"��"};
    unsigned char watersbuf[] = {"��ˮ"};
	unsigned char ch1sbuf[] = {"�쳣"};
	unsigned char ch2sbuf[] = {"����"};
	unsigned char tdsbuf[]  = {"�ر�"};
	unsigned char cssbuf[]  = {"�ر�"};
	unsigned char tusbuf[]  = {"�ر�"};
	unsigned char jssbuf[]  = {"�ر�"};
	unsigned char chzsbuf[] = {"ͨ�Ź���"};
	
	unsigned char pwrsbuf[] = {"ע��"};
	unsigned char pwrCH1buf[] = {"�ر�    "};
	unsigned char pwrCH2buf[] = {"�ر�    "};
	unsigned char pwrCH3buf[] = {"�ر�    "};
	unsigned char pwrCH4buf[] = {"�ر�    "};
	unsigned char pwrCH5buf[] = {"�ر�    "};
	unsigned char pwrCH6buf[] = {"�ر�    "};
	
	if(DeviceStatus.Enable == TRUE)  memcpy(devsbuf,"������", sizeof(devsbuf));//
	if(DeviceStatus.Internet != Err) memcpy(netsbuf,"��������",sizeof(netsbuf));//
	if(DeviceStatus.GPRS != Err)     memcpy(gprsbuf,"��������",sizeof(netsbuf));//
	if(DeviceStatus.AGPS != Err)     memcpy(gpsbuf,"��ȡ�ɹ�",sizeof(netsbuf));//
	if(Device.WSDStatus[1]  != 0x00 ) temp = ~temp;
	if(Device.PutInStatus[0][0] == 0x11)   memcpy(gmsbuf,"�ر�",sizeof(gmsbuf)); //
	if(Device.WSDStatus[8]   == 0x30)      memcpy(watersbuf,"����",sizeof(watersbuf)); //
	if(Device.PutInStatus[1][0] == 0x21)   memcpy(ch1sbuf,"����",sizeof(ch1sbuf)); //
	if(Device.PutInStatus[2][0] == 0x31)   memcpy(ch2sbuf,"����",sizeof(ch2sbuf)); //
	if(Device.PutOutStatus[0][0]== 0x11)   memcpy(tdsbuf,"����",sizeof(tdsbuf)); //
	if(Device.PutOutStatus[1][0] == 0x21)  memcpy(cssbuf,"����",sizeof(cssbuf)); //
	if(Device.PutOutStatus[2][0] == 0x31)  memcpy(tusbuf,"����",sizeof(tusbuf)); //
	if(Device.PutOutStatus[3][0] == 0x41)  memcpy(jssbuf,"����",sizeof(jssbuf)); //
	if(Device.PutOutStatus[3][0] == 0x41)  memcpy(jssbuf,"����",sizeof(jssbuf)); //
	if(Device.CHZStatus[0] == 0x01)        memcpy(chzsbuf,"����",sizeof(jssbuf)); //
	else if(Device.CHZStatus[0] == 0x00)   memcpy(chzsbuf,"�ر�",sizeof(jssbuf)); //
	
	if(DeviceStatus.PwrEnable == TRUE)     memcpy(pwrsbuf,"����",sizeof(pwrsbuf)); //
	if(Device.PwrStatus[0][0] == 0x11)     memcpy(pwrCH1buf,"����    ",sizeof(pwrCH1buf)); //
	if(Device.PwrStatus[1][0] == 0x21)     memcpy(pwrCH2buf,"����    ",sizeof(pwrCH1buf)); //
	if(Device.PwrStatus[2][0] == 0x31)     memcpy(pwrCH3buf,"����    ",sizeof(pwrCH1buf)); //
	if(Device.PwrStatus[3][0] == 0x41)     memcpy(pwrCH4buf,"����    ",sizeof(pwrCH1buf)); //
	if(Device.PwrStatus[4][0] == 0x51)     memcpy(pwrCH5buf,"����    ",sizeof(pwrCH1buf)); //
	if(Device.PwrStatus[5][0] == 0x61)     memcpy(pwrCH6buf,"����    ",sizeof(pwrCH1buf)); //
	
    if(DeviceStatus.AdminHttp == TRUE) //�ѵ�¼
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
				devsbuf,//�豸״̬
				netsbuf,//����״̬
				gprsbuf,//GPRS״̬
				gpsbuf,//GPS״̬
				temp/10,abs((~temp)%10),"��",//�豸�¶�
				((Device.WSDStatus[6]<<8) + Device.WSDStatus[7])/10,((Device.WSDStatus[6]<<8) + Device.WSDStatus[7])%10,"%", //�豸ʪ��
				gmsbuf,//����״̬
				watersbuf,//��ˮ״̬
				ch1sbuf,
				ch2sbuf,
				tdsbuf,
				cssbuf,
				tusbuf,
				jssbuf,
				chzsbuf,
				((Device.CHZStatus[4]<<8)+Device.CHZStatus[5])/10,"V",//��ѹ
				((Device.CHZStatus[8]<<8)+Device.CHZStatus[9])/10,((Device.CHZStatus[8]<<8)+Device.CHZStatus[9])%10,"A",//����
				((Device.CHZStatus[12]<<8)+Device.CHZStatus[13])/10,"mA",//©��
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
   }else //û�е�¼
   {
//      sprintf(buf,"settingsCallback({\"admin\":\"%s\",\
//									 \"password\":\"%s\"});",
//				"�û���","����"
//			  ); //ʹ��placeholder
   }
}

/**
*@brief		���http��Ӧ
*@param		��
*@return	��
*/
void HttpServer(void)
{
    uint8_t ch=SOCK_HTTPS;								/*����һ��socket*/
    uint16_t len;

    st_http_request *http_request;						/*����һ���ṹָ��*/
    memset(rx_buf,0x00,MAX_URI_SIZE);
    http_request = (st_http_request*)rx_buf;
    /* http service start */
    switch(getSn_SR(ch))								/*��ȡsocket״̬*/
    {
    case SOCK_INIT:									/*socket���ڳ�ʼ��״̬*/
        listen(ch);
        break;

    case SOCK_LISTEN:								  /*socket���ڼ���״̬*/
        break;

    case SOCK_ESTABLISHED:							   /*socket��������״̬*/
        if(getSn_IR(ch) & Sn_IR_CON)
        {
            setSn_IR(ch, Sn_IR_CON);				    /*����жϱ�־λ*/
        }
        if ((len = getSn_RX_RSR(ch)) > 0)
        {
            len = recv(ch, (uint8_t*)http_request, len); /*����http����*/
            *(((uint8_t*)http_request)+len) = 0;
            proc_http(ch, (uint8_t*)http_request);		/*����http���󲢷���http��Ӧ*/
            disconnect(ch);
        }
        break;

    case SOCK_CLOSE_WAIT:   											/*socket���ڵȴ��ر�״̬*/
        if ((len = getSn_RX_RSR(ch)) > 0)
        {
            len = recv(ch, (uint8_t*)http_request, len);				/*����http����*/
            *(((uint8_t*)http_request)+len) = 0;
            proc_http(ch, (uint8_t*)http_request);						/*����http���󲢷���http��Ӧ*/
        }
        disconnect(ch);
        break;

    case SOCK_CLOSED:                   									/*socket���ڹر�״̬*/
        socket(ch, Sn_MR_TCP, 80, 0x00);   									/*��socket*/
        break;

    default:
        break;
    }
}

/**
*@brief		����http�����Ĳ�����http��Ӧ
*@param		s: http������socket
*@param		buf��������������
*@return	��
*/
void proc_http(SOCKET s, uint8_t * buf)
{
    char* name;
    char req_name[32]= {0x00,};		/*����һ��http��Ӧ���ĵ�ָ��*/
    unsigned long file_len=0;		/*����http������ͷ�Ľṹ��ָ��*/
    uint16_t send_len=0;
    uint8_t* http_response;
    st_http_request *http_request;
    memset(tx_buf,0x00,MAX_URI_SIZE);
    http_response = (uint8_t*)rx_buf;
    http_request = (st_http_request*)tx_buf;
    parse_http_request(http_request, buf);    	/*����http������ͷ*/

    switch (http_request->METHOD)
    {
    case METHOD_ERR :																			/*������ͷ����*/
        memcpy(http_response, ERROR_REQUEST_PAGE, sizeof(ERROR_REQUEST_PAGE));
        send(s, (uint8_t *)http_response, strlen((char const*)http_response));
        break;

    case METHOD_HEAD:																			/*HEAD����ʽ*/

    case METHOD_GET:																			/*GET����ʽ*/
        name = http_request->URI;
        if(strcmp(name,"/index.htm")==0 || strcmp(name,"/")==0 || (strcmp(name,"/index.html")==0))
        {
            if(DeviceStatus.AdminHttp == TRUE) //�ѵ�¼
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
					if(DeviceStatus.AdminHttp == TRUE) //�ѵ�¼
                      send(s, (uint8_t *)INDEX_HTML+send_len, 1024);
					else
					  send(s, (uint8_t *)Admin_HTML+send_len, 1024);
                    send_len+=1024;
                    file_len-=1024;
                }else
                {
					if(DeviceStatus.AdminHttp == TRUE) //�ѵ�¼
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
    case METHOD_POST:	/*POST����*/
        mid(http_request->URI, "/", " ", req_name);	/*��ȡ��������ļ���*/
        if(strcmp(req_name,"config.cgi")==0)
        { 					
            if(DeviceStatus.AdminHttp == TRUE) //�ѵ�¼
			{
				cgi_ipconfig(http_request);	/*��������Ϣд����Ƭ��eeprom*/
				make_cgi_response(10,(char*)ConfigMsg.lip,tx_buf);	/*������Ӧ���ı�����*/
				sprintf((char *)http_response,"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length:%d\r\n\r\n%s",strlen(tx_buf),tx_buf);
				/*����http��Ӧ*/
				send(s, (unsigned char *)http_response, strlen((char *)http_response));
			}else
			{
			    cgi_ipconfig(http_request);	/*��������Ϣд����Ƭ��eeprom*/
				make_cgi_response(3,(char*)ConfigMsg.lip,tx_buf);	/*������Ӧ���ı�����*/
				sprintf((char *)http_response,"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length:%d\r\n\r\n%s",strlen(tx_buf),tx_buf);
				/*����http��Ӧ*/
				send(s, (unsigned char *)http_response, strlen((char *)http_response));
			}
            disconnect(s);										/*�Ͽ�socket����*/
            if((HttpRoboot == TRUE)&&(DeviceStatus.AdminHttp == TRUE)) 
				ReBoot_Flag = TRUE;			/*������־λ��1*/
			else HttpRoboot =FALSE;
            return;
        }
	
        break;

    default :
        break;
    }
}

/**
*@brief		��������Ϣд����Ƭ��eeprom
*@param		http_request������һ��http����Ľṹ��ָ��
*@return	��
*/
void cgi_ipconfig(st_http_request *http_request)
{
    uint8_t  i;
	uint8_t  *param;
	uint32_t port =0;
	uint8_t  adminbuff[12];
	CONFIG_MSG  NetConfigMsg;
	if(DeviceStatus.AdminHttp == TRUE) //�ѵ�¼
	{
		param = get_http_param_value(http_request->URI,"ip");		/*��ȡ�޸ĺ��IP��ַ*/
		if(param)
		{
			inet_addr_((uint8_t*)param, NetConfigMsg.lip);
		}
		param = get_http_param_value(http_request->URI,"gw");		/*��ȡ�޸ĺ������*/
		if(param)
		{
			inet_addr_((uint8_t*)param, NetConfigMsg.gw);
		}
		param = get_http_param_value(http_request->URI,"sub");	/*��ȡ�޸ĺ����������*/
		if(param)
		{
			inet_addr_((uint8_t*)param, NetConfigMsg.sub);
		}
		param = get_http_param_value(http_request->URI,"port");	/*��ȡ�޸ĺ�Ķ˿ں�*/
		if(param)
		{
			for(i=0;i<5;i++) adminbuff[i] = *(param+i);	
			port = Intnet_Port(adminbuff); 
			if(port>0) NetConfigMsg.port = Intnet_Port(adminbuff);
			else   NetConfigMsg.port = ConfigMsg.port; 
		}
		param = get_http_param_value(http_request->URI,"Rip");	/*��ȡ�޸ĺ�ķ�����IP*/
		if(param)
		{
			inet_addr_((uint8_t*)param, NetConfigMsg.serip);
		}
		param = get_http_param_value(http_request->URI,"Rport");	/*��ȡ�޸ĺ�ķ������˿ں�*/
		if(param)
		{
			for(i=0;i<5;i++) adminbuff[i] = *(param+i);	
			port = Intnet_Port(adminbuff); 
			if(port>0)  NetConfigMsg.serport = Intnet_Port(adminbuff); 
            else NetConfigMsg.serport = ConfigMsg.serport;			
		}param = get_http_param_value(http_request->URI,"Gip");	/*��ȡ�޸ĺ��GPRS������IP*/
		if(param)
		{
			inet_addr_((uint8_t*)param, NetConfigMsg.gprsip);
		}
		param = get_http_param_value(http_request->URI,"Gport");	/*��ȡ�޸ĺ��GPRS�������˿ں�*/
		if(param)
		{
			for(i=0;i<5;i++) adminbuff[i] = *(param+i);	
			port = Intnet_Port(adminbuff); 
			if(port>0) NetConfigMsg.gprsport = Intnet_Port(adminbuff); 
            else 	NetConfigMsg.gprsport =	ConfigMsg.gprsport;	
		}
	   for(i=0;i<12;i++) adminbuff[i] = 0;
	   param = get_http_param_value(http_request->URI,"admin");		/*��ȡ�޸ĺ��IP��ַ*/
	   if(param)
	   {
	      for(i=0;i<6;i++)
		   adminbuff[i] = *(param+i);
	   }
	   param = get_http_param_value(http_request->URI,"password");	/*��ȡ�޸ĺ��IP��ַ*/
	   if(param)
	   {
	      for(i=0;i<6;i++)
		   adminbuff[i+6] = *(param+i);
	   }	
       Save_config_to_eeprom(NetConfigMsg,adminbuff);			/*����ȡ���������д��eeprom*/	
	   HttpRoboot = TRUE;  //ϵͳ����������־
	}else
	{
	   param = get_http_param_value(http_request->URI,"admin");		/*��ȡ�޸ĺ��IP��ַ*/
	   if(param)
	   {
	      for(i=0;i<6;i++)
		   adminbuff[i] = *(param+i);
	   }
	   param = get_http_param_value(http_request->URI,"password");	/*��ȡ�޸ĺ��IP��ַ*/
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
*@brief		ִ��http��Ӧ
*@param		��
*@return	��
*/
void make_cgi_response(uint16_t delay, char* url,char* cgi_response_buf)
{
    sprintf(cgi_response_buf,"<html><head><title>iWeb - Configuration</title><script language=javascript>j=%d;function func(){document.getElementById('delay').innerText=' '+j + ' ';j--;setTimeout('func()',1000);if(j==0)location.href='http://%d.%d.%d.%d/';}</script></head><body onload='func()'>please wait for a while, the module will boot in<span style='color:red;' id='delay'></span> seconds.</body></html>",delay,url[0],url[1],url[2],url[3]);
    return;
}

/**
*@brief		ִ��http��Ӧ
*@param	    ʵ�ֹ��ܣ�1.�豸IPȫ��Ϊ0.0.0.0ʱ��Ĭ���Ǵ���ģ�ҳ�����õĲ��������޸ĵ�
                      2.�û�������ȫ��Ϊ0ʱ��Ĭ���Ǵ���ģ�ҳ�����õĲ��������޸ĵ�
*@return	��
*/
static void Save_config_to_eeprom(CONFIG_MSG  NetConfigMsg,u8 *str)
{
    u8 admin =0;
	u8 datatemp[40]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
    for(u8 i=0;i<4;i++) //�豸IP
	{
		if(NetConfigMsg.lip[i] > 0) 
		{   //�豸�������
		    memcpy(datatemp,NetConfigMsg.lip, 4); 
			memcpy(datatemp+4,NetConfigMsg.sub, 4);
			memcpy(datatemp+8,NetConfigMsg.gw, 4); 
			memcpy(datatemp+12,NetConfigMsg.dns, 4);
			datatemp[16] = NetConfigMsg.port>>8;
			datatemp[17] = NetConfigMsg.port&0xFF;
			datatemp[18] = 0xAA;
			datatemp[19] = 0x55;
			
			//�������������
			memcpy(datatemp+20,NetConfigMsg.serip, 4); 
			datatemp[24] = NetConfigMsg.serport>>8;
			datatemp[25] = NetConfigMsg.serport&0xFF;
			datatemp[26] = 0xAA;
			datatemp[27] = 0x55;
			//GPRS�������������
			memcpy(datatemp+28,NetConfigMsg.gprsip,4); 
			datatemp[32] = NetConfigMsg.gprsport>>8;
			datatemp[33] = NetConfigMsg.gprsport&0xFF;
			datatemp[34] = 0xAA;
			datatemp[35] = 0x55;			
			Save_NetMsg_E2PROM(NetMsgPage,datatemp,40);	
			//�û���
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

//��Դ��ѹ��ʾ����
static u16 PwrVin(u16 data)
{
  if( data>= 4000) return 0;
	else return data/10;

}







