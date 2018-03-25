#ifndef	__HTTPUTIL_H__
#define	__HTTPUTIL_H__

#include "w5500.h"
#include "W5500_conf.h"
#include "http_server.h"
#include "W5500_socket.h"

void HttpServer(void);
void proc_http(SOCKET s, unsigned char * buf);
void cgi_ipconfig(st_http_request *http_request);
//void trimp(uint8* src, uint8* dst, uint16 len);
uint16_t make_msg_response(uint8_t* buf,char* msg);

void make_cgi_response(uint16_t a,char* b,char* c);
void make_pwd_response(char isRight,uint16_t delay,char* cgi_response_content, char isTimeout);
#endif


