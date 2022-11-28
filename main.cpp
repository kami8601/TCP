///client.c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<iostream>
#include<vector>
#include <thread>

#define BUFFER_SIZE 100

void client_Init(void);
void receive(bool qw);
void SEND(void);

using namespace std;


int sockfd,client_fd;
int len;
char buf[BUFFER_SIZE];
struct sockaddr_in servaddr;
bool as=true;


int main()
{

    client_Init();
    
    
    
    receive(as);
}


void client_Init(void)
{   
    /*创建socket*/
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==-1)
    {
        perror("socket");
        exit(-1);
    }
    else
    {
        cout<<"socket build success"<<endl;
    }

    /*创建sockaddr_in结构体中相关参数*/
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(5000);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    /*调用connect函数主动发起对服务端的链接*/
    if(connect(sockfd,(struct sockaddr *) &servaddr,sizeof(servaddr))==-1)
    {
        perror("connect");
        exit(-1);
    }
}

void receive(bool qw)
{
    while(qw)
    {
        // printf("please input string:\r\n");					
        // scanf("%s",buf);
        // len = sizeof(buf);
        // printf("len = %d\r\n",len);
        // buf[len] = 0;
        send(sockfd,"1",strlen("1"),0);
      
        // memset(buf,0,sizeof(buf));
        recv(sockfd,buf,BUFFER_SIZE,0);
        printf("Received a message:%s\n",buf);
        if(atoi(buf)==2)
        {
            cout<<"sdada"<<endl;
            //qw=false;
        }
        memset(buf,0,sizeof(buf));
    }
    close(sockfd);
}

// void SEND(void)
// {
//     while(1)
//     {
//     send(sockfd,"rty",sizeof("rty"),0);
//     sleep(2);
//     }
// }
