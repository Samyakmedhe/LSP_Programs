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
    
    return 0;
}