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

    if(iRet == 0 )
    {
        printf("Named pipe gets sucessfully created\n");
    }


    return 0;
}