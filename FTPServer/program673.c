///////////////////////////////
//
//  Client Code
//
//////////////////////////////


#include<stdio.h>       // printf , scanf
#include<stdlib.h>      // malloc , free
#include<string.h>      // memset , memcmp

#include<unistd.h>      // close , write, read
#include<fcntl.h>       // creat , unlink

#include <sys/socket.h> // socket , bind , listen , accept , connect
#include<netinet/in.h>  // sockaddr_in, htons

#include<arpa/inet.h>

int main()
{
    int ServerSocketFd = 0;
    int iRet = 0 ;
    int Port = 11000;
    
    char Buffer[1024] = {'\0'};
    struct sockaddr_in ServerAddr;
    
    // step 1 : Create TCP socket
    ServerSocketFd = socket(AF_INET , SOCK_STREAM , 0);

    if(ServerSocketFd < 0 )
    {
        printf("Unable to create socket\n");
        return -1;
    }

    printf("Socket gets created successufully with fd : %d\n",ServerSocketFd);

    
    // Step 2 : Connect with server 
    memset(&ServerAddr , 0 , sizeof(ServerAddr));

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(Port);
    
    inet_pton(AF_INET , "127.0.0.1", &ServerAddr.sin_addr);

    iRet = connect(ServerSocketFd,(struct sockaddr * )&ServerAddr, sizeof(ServerAddr));

    if(iRet == -1)
    {
        printf("Unable to connect with server\n");
        return -1;
    }

    printf("Client successfully connected with server\n ");
    
    iRet =  read(ServerSocketFd , Buffer , sizeof(Buffer) - 1);
    
    if(iRet <= 0)
    {
        printf("Unable to read the data from server\n");
        return -1;

    }
    printf("Data from server is %s\n", Buffer);

    // step  4 : close all resoruces
    close(ServerSocketFd);
    printf("Terminating the client application\n");
    return 0;
}