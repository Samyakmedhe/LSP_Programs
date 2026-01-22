// name pipe Server 

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{
    int fd = 0 ;
    int iRet = 0 ;

    iRet = mkfifo("/tmp/marvellous",0666);

    if(iRet == -1 )
    {
        printf("Unable to create Named pipe \n");
        return -1;
    }

    fd = open("/tmp/marvellous",O_WRONLY);
    if(fd == -1)
    {
        printf("Unable to open name pipe\n");
        return -1;
    }

    write(fd , "Jay Ganesh", 10);

    printf("Data gets sucessfully written into the pipe by the server\n");
    close(fd);

    unlink("/tmp/marvellous");
    
    return 0;
}