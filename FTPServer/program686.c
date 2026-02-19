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
#include<sys/stat.h>
#include<unistd.h>      // close , write, read
#include<fcntl.h>       // creat , unlink

#include <sys/socket.h> // socket , bind , listen , accept , connect
#include<netinet/in.h>  // sockaddr_in, htons

#include<arpa/inet.h> 

#include<stdbool.h> // true false


void SendFileToClient(int ClientSocket , char * Filename)
{
    int fd = 0;
    struct stat sobj;
    char Buffer[1024];
    int BytesRead = 0;
    char Header[64] = {'\0'};

    printf("File Name : %s : %ld\n",Filename, strlen(Filename));
    fd = open(Filename, O_RDONLY);

    // Unable to  open file
    if(fd < 0 )
    {
        printf("Unable to File\n");
        // Send error message to client
        write(ClientSocket, "ERR\n",4);
        return;
    }

    stat(Filename , &sobj);

    // Header : "OK 1700";
    snprintf(Header , sizeof(Header), "OK %ld\n",(long)sobj.st_size);

    // write Header to client 

    write(ClientSocket , Header, strlen(Header));

    // Send actual file contents
    while((BytesRead = read(fd , Buffer ,sizeof(Buffer))) > 0 )
    {
        // Send the data to client 
        write(ClientSocket, Buffer, BytesRead);
    }

    close(fd);

}


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

    char Filename[50] = {'\0'};

    pid_t pid = 0 ;

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
        
        /////////////////////////////////////////////////////////////////////////////////////////////
        //  
        //      Step 5 : create new process to handle client request
        //
        /////////////////////////////////////////////////////////////////////////////////////////////

        pid = fork();

        if(pid < 0)
        {
            printf("Unable to create a new process for client request\n");
            close(ClientSocket);

            continue;
        }

        // New process gets created for client
        if(pid == 0)
        {
            printf("new Process is created for client request\n");

            close(ServerSocket);

            iRet = read(ClientSocket, Filename , sizeof(Filename));
            printf("Requested file by clients : %s\n", Filename);

            Filename[strcspn(Filename, "\r\n")] = '\0';
            
            SendFileToClient(ClientSocket , Filename);
            
            close(ClientSocket);
        
            printf("File Transfer done & Client Disconneted\n");

            exit(0); // kill the child process
        }// End of if (fork)
        else // Parent Process (Server)
        {
            close(ClientSocket);

        }// End of else
    }// End of while

    close(ServerSocket);


    return 0;
} // End of main