// name pipe Client 

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

    char Arr[100] = {'\0'};

    fd = open("/tmp/marvellous",O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open name pipe\n");
        return -1;
    }

    read(fd ,Arr,3);

    printf("Data gets sucessfully Read from the pipe by the client\n");
    printf("Data is : %s\n",Arr);

    close(fd);
    
//////////////////////////////////////////////////////////////////////////////////


    fd = open("/tmp/marvellous",O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open name pipe\n");
        return -1;
    }

    read(fd ,Arr,7);

    printf("Data gets sucessfully Read from the pipe by the client\n");
    printf("Data is : %s\n",Arr);

    close(fd);
    return 0;
}