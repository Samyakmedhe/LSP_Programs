#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/types.h>

int main()
{
    char Path[50];

    getcwd(Path ,sizeof(Path));
    printf("Current Directory Name : %s\n",Path);

    chdir("./Data");

    getcwd(Path , sizeof(Path));
    printf("Current Directory Name : %s\n",Path);

    open("sycn_1.c");

    return 0;
}