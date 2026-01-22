#include<fcntl.h>
#include<stdio.h>

int main()
{
    int fd = 0;

    fd = open("Second.c", O_CREAT,0777);

    if(fd == -1 )
    {
        printf("Unable to open file\n");
    }
    else
    {
        printf("File gets Succesfully created with fd : %d\n",fd);
    }

    return 0 ;
}