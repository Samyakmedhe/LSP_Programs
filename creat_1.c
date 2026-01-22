#include<fcntl.h>
#include<stdio.h>

int main()
{
    int fd = 0;

    fd = creat("LSP.txt", 0777);

    if(fd == -1)
    {
        printf("Unable to creat file\n");
    }
    else
    {
        printf("File gets successfully created with fd : %d\n",fd);
    }

    return 0;
}