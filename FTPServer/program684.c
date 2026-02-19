/////////////////////////////////////////////////////////////////////////////////////////////
//
//  
//      CLIENT APPLICATION
//
//
/////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>       // printf , scanf
#include<stdlib.h>      // malloc , free
#include<string.h>      // memset , memcmp

#include<unistd.h>      // close , write, read
#include<fcntl.h>       // creat , unlink

#include <sys/socket.h> // socket , bind , listen , accept , connect
#include<netinet/in.h>  // sockaddr_in, htons

#include<arpa/inet.h> 

#include<stdbool.h> // true false


/////////////////////////////////////////////////////////////////////////////////////////////
//
//  CommandLine Argument Application
//  1st Argument : IP Address
//  2nd Argument : Port Number
//  3rd Argument : Target file name
//  4th Argument : new file name  
//  
// ./client     127.0.0.1       9000        Demo.txt    A.txt
//  argv[0]     argv[1]         argv[2]     argv[3]     argv[4]
//
//  argc = 5
//
/////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc , char * argv[])
{
    int Sock = 0;               // argv[2]
    int Port = 0;
    int iRet = 0;

    char * ip = NULL;           // argv[1]
    char *Filename = NULL;      // argv[3]
    char *OutFilename = NULL;   // argc[4]

    struct sockaddr_in ServerAddr;
    
    if(argc < 5 || argc > 5)
    {
        printf("Unable to processed as invalid number of arguments\n");
        
        printf("Please provide below arguments : \n");
        
        printf("1st Argument : IP Address\n");
        printf("2nd Argument : Port Number\n");
        printf("3rd Argument : Target file name\n");
        printf("4th Argument : new file name\n");

        return -1;
    }

    // Store Command line Argument into variables
    ip = argv[1];
    Port = atoi(argv[2]);
    Filename = argv[3];
    OutFilename = argv[4];
    
    ////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Step 1 : Create TCP socket
    //
    ////////////////////////////////////////////////////////////////////////////////////////////
   
    Sock = socket(AF_INET , SOCK_STREAM , 0);
    
    if(Sock <  0 )
    {
        printf("Unable to create client socket\n");
        return -1;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Step 2 : Connect with server 
    //
    ////////////////////////////////////////////////////////////////////////////////////////////

    memset(&ServerAddr , 0 , sizeof(ServerAddr));

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(Port);

    // Convert the IP address into binaray format
    
    inet_pton(AF_INET , ip , &ServerAddr.sin_addr);

    iRet = connect(Sock , (struct sockaddr*)&ServerAddr, sizeof(ServerAddr));

    if(iRet == -1)
    {
        printf("Unable to connect with server\n");
        close(Sock);
        return -1;
    }
    // Sending file name to server
    write(Sock,Filename, strlen(Filename));

    return 0;
} // End of main