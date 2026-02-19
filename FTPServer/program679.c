/////////////////////////////////////////////////////////////////////////////////////////////
//
//  
//      SERVER APPLICATION
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
//  1st Argument : Port Number
//  ./Server     9000 
//   argv[0]     argv[1]
//
/////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc , char * argv[])
{
    int ServerSocket = 0;
    int ClientSocket = 0;
    int Port = 0;
    int iRet = 0;

    struct sockaddr_in ServerAddr;
    struct sockaddr_in ClientAddr;

    socklen_t Addrlen = sizeof(ClientAddr);

    if((argc < 2) || (argc > 2)) // ERROR Handling
    {
        printf("Unable to processed as invalid number of arguments\n");
        printf("Please provide the port number\n");
        
        return -1;
    }

    // Port Number of Server
    Port = atoi(argv[1]);

    /////////////////////////////////////////////////////////////////////////////////////////////
    //  
    //  Step 1 : Create TCP Socket
    //
    /////////////////////////////////////////////////////////////////////////////////////////////

    ServerSocket = socket(AF_INET , SOCK_STREAM , 0);

    if(ServerSocket < 0)
    {
        printf("Unable to create server socket\n");
        return -1;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //  
    //  Step 2 : Bind socket to IP and Port
    //
    /////////////////////////////////////////////////////////////////////////////////////////////

    memset(&ServerAddr , 0 , sizeof(ServerAddr));

    // Initialise the structure

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(Port);
    ServerAddr.sin_addr.s_addr = INADDR_ANY;

    iRet = bind(ServerSocket ,(struct sockaddr * )&ServerAddr, sizeof(ServerAddr));

    if(iRet == -1 )
    {
        printf("Unable to bind\n");
        close(ServerSocket);
        return -1;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    //  
    //  Step 3 : List for client connections
    //
    /////////////////////////////////////////////////////////////////////////////////////////////

    iRet = listen(ServerSocket , 11);

    if(iRet == - 1)
    {
        printf("Unable to listen the request\n");
        close(ServerSocket);
        return -1;
    }

    printf("Server is Running on port %d\n",Port);
    

    /////////////////////////////////////////////////////////////////////////////////////////////
    //  
    //  Loop which accept client request continiously
    //
    /////////////////////////////////////////////////////////////////////////////////////////////

    // Loop to accept multiple client requests
    while(1)
    {
        /////////////////////////////////////////////////////////////////////////////////////////////
        //  
        //      Step 4 : Accept the client request
        //
        /////////////////////////////////////////////////////////////////////////////////////////////

        memset(&ClientAddr , 0 , sizeof(ClientAddr));

        printf("Server is waiting for client request...\n");

        ClientSocket = accept(ServerSocket,(struct sockaddr *)&ClientAddr, &Addrlen);

        if(ClientSocket < 0 )
        {
            printf("unable to accept client request\n");

            continue;   // for while
        }

        printf("Client gets connected : %s\n",inet_ntoa(ClientAddr.sin_addr));


    }// End of while


    return 0;
} // End of main