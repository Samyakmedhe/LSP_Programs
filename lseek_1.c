#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

#define SIZE_BUFFER 100



int main()
{
    int fd = 0 ;
    char Buffer[SIZE_BUFFER];

    int iRet = 0 ;

    memset(Buffer , '\0',SIZE_BUFFER);   // Change 

    fd = open("Demo.txt",O_RDONLY);

    if(fd < 0 )
    {
        printf("Enable to open file\n");
        printf("Reason : %s\n",strerror(errno));
        return -1;
    }

    printf("File Successfully open with fd : %d\n",fd);

    iRet = lseek(fd , 10 , SEEK_CUR);

    printf("Updated file offset is : %d\n",iRet);

    close(fd);

    return 0;
}