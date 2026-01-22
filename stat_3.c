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

    printf("Inode Number : %ld\n",sobj.st_ino);
    printf("hardlink count : %ld\n",sobj.st_nlink);
    printf("Total size : %ld\n",sobj.st_size);
    printf("block size : %ld\n",sobj.st_blksize);


    printf("File type is : %d\n",sobj.st_mode);
    

    return 0;    
    
}