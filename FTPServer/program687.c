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


int Readline(int Sock , char *line , int max)
{
    int i = 0 ;
    char ch = '\0';
    int n = 0 ;

    while(i < max - 1)
    {
        n = read(Sock , &ch , 1);
        if(n <= 0 )
        {
            break;
        }
        line[i++] = ch;

        if(ch == '\n')
        {
            break;
        }
    }   // End of while
    line[i] = '\0';
    return i ;
}

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

    char Header[64] = {'\0'};
    
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
    ////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Step 3 : Send file name
    //
    ////////////////////////////////////////////////////////////////////////////////////////////
    
    write(Sock,Filename, strlen(Filename));
    write(Sock,"\n",1);

    ////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Step 4 : Read the Header
    //
    ////////////////////////////////////////////////////////////////////////////////////////////

    iRet = Readline(Sock, Header , sizeof(Header));

    if(iRet <= 0 )
    {
        printf("Server gets disconnected abnormally\n");
        close(Sock);
        return -1;
    }

    long FileSize = 0;
    sscanf(Header, "OK %ld", &FileSize);

    printf("File size is : %ld\n",FileSize);

    ////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Step 5 : Create new file
    //
    ////////////////////////////////////////////////////////////////////////////////////////////

    int outfd = 0;
    outfd = open(OutFilename, O_CREAT | O_WRONLY | O_TRUNC, 0777);

    if(outfd < 0 )
    {
        printf("Unable to create downloaded file\n");
        return -1;
    }

    char Buffer[1024] = {'\0'};
    long received  = 0;
    long remaining = 0;

    int n = 0;
    int toRead = 0;

    while(received < FileSize)
    {
        remaining = FileSize - received;

        if(remaining > 1024)
        {
            toRead = 1024;
        }
        else
        {
            toRead = remaining;
        }

        n = read(Sock , Buffer , toRead);

        write(outfd , Buffer , n );
        
        received = received + n;

    }  // End of while

    close(outfd);
    close(Sock);

    if(received == FileSize)
    {
        printf("Download complete...\n");
        return 0;
    }
    else
    {
        printf("Download failed...\n");
        return -1;
    }


    return 0;
} // End of main