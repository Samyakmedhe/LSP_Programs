#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main()
{
    int fd = 0 ;
    char Buffer[] = "indiaismycountry";
    int iRet = 0 ;

    fd = open("Demo.txt",O_CREAT |O_WRONLY | O_APPEND, 0777); // IMP

    if(fd < 0 )
    {
        printf("Enable to open file\n");
        printf("Reason : %s\n",strerror(errno));
        return -1;
    }

    printf("File Successfully open with fd : %d\n",fd);

    iRet = write(fd, Buffer , 16); // Overwtite isssue 
    
    printf("%d bytes gets successfully written\n",iRet);
    
    fdatasync(fd); 
    // Process is in waiting state 
 
    close(fd);

    
    

    return 0;
}
