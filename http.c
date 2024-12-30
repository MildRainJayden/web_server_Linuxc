//http模块实现
#include<unistd.h>
//#include<sys/syscall.h>  局限于linux系统，用下行头文件替代？
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include"http.h"

//http请求的解析
parseRequest(const char* req,HTTP_REQUEST* hreq){
    sscanf(req,"%s%s%s",hreq->method,hreq->path,hreq->protocol);
    strstr(req,"connection");
    return 0;
}

//http协议演示
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>

int main(void){
    // 客户端
    //创建套接字
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1){
        perror("socket");
        return -1;
    }
    //组织百度服务器地址结构
    struct sockaddr_in ser;
    ser.sin_family = AF_INET;
    ser.sin_port = htons(80);//默认80端口
    ser.sin_addr.s_addr = inet_addr("110.242.68.4");
    //发起连接
    if(connect(sockfd,(struct sockaddr*)&ser,sizeof(ser)) == -1){
        perror("connect");
        return -1;
    }
    //组织http请求
    char request[1024] = {};

    //路径 /  表示要服务器的首页文件
    sprintf(request,"GET / HTTP/1.1\r\n"
                    "Host: www.baidu.com\r\n"
                    "Accept: */*\r\n"
                    "Connection: close\r\n\r\n");
    //发送
    if(send(sockfd,request,strlen(request),0) == -1){
        perror("send");
        return -1;
    }
    //接收百度回传的响应
    for(;;){
        char respond[1024] = {};
    }
    return 0;
}






