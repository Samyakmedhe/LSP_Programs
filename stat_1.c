#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{
    struct stat sobj; 
    int iRet = 0 ;
    stat("Demo.txt",&sobj);

    iRet = stat("Demo.txt",&sobj);

    if(iRet == 0 )
    {
        printf("Stat works successfully\n");
    }
    else
    {
        printf("there is issue in stat\n");
        return -1;
    }

    return 0;    
    
}