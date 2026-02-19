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


int main()
{
    int ServerSocketFd = 0;

    // step 1 : Create TCP socket
    ServerSocketFd = socket(AF_INET , SOCK_STREAM , 0);

    if(ServerSocketFd < 0 )
    {
        printf("Unable to create socket\n");
        return -1;
    }

    printf("Socket gets created successufully with fd : %d\n",ServerSocketFd);

    


    return 0;
}