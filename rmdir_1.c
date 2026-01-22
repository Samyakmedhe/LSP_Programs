#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>


int main()
{
    int iRet = 0 ;

    iRet = rmdir("./Data");

    if(iRet == 0 )
    {
        printf("Directory gets Deleted\n");
    }
    else
    {
        printf("%s\n",strerror(errno));
    }
    
    return 0;
}