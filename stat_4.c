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
    if(S_ISBLK(sobj.st_mode))
    {
        printf("Block Device\n");
    }
    else if(S_ISCHR(sobj.st_mode))
    {
        printf("Character Device\n");
    }
    else if(S_ISDIR(sobj.st_mode))
    {
        printf("Directory file\n");
    }
    else if(S_ISREG(sobj.st_mode))
    {
        printf("Regular file\n");
    }
    else if(S_ISSOCK(sobj.st_mode))
    {
        printf("Socke file\n");
    }
    else if(S_ISFIFO(sobj.st_mode))
    {
        printf("Pipe file\n");
    }
    else if(S_ISLNK(sobj.st_mode))
    {
        printf("Symbolic link\n");
    }

    return 0;    
    
}