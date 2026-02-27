//          ./touchx       File Name 
//          argv[0]         argv[1]         
//          argc = 2

/*
    Step 1 : 
        Accept file from command line
    
    Step 2:
        Check weather file is existing or not

    Step 3 :
        If it is Existing then print on console
    
    Step 4 :
        If it is not existing
    
    Step 5 :
        Display No such file or directory  as a error
*/


#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

# define MAX_BUFFER_SIZE 1024

int main(int argc , char * argv[])
{
    if(argc != 2)
    {
        printf("ERROR : Insufficient Arguments\n");
        printf("Use command as :    ./catx   FileName  \n");

        return 1;
    }

    if(access(argv[1], F_OK) != 0 )
    {
        printf("cat: %s : No such file or directory\n",argv[1]);
        return -1;
    }
    else
    {
        int fd = 0 , iRet = 0;

        fd = open(argv[1], O_RDONLY);


        if(fd < 0)
        {
            printf("ERROR : Unable to open file\n");
        }
        char Buffer[MAX_BUFFER_SIZE] = {'\0'};


        while((iRet = read(fd , Buffer , sizeof(Buffer))) != 0 )
        {
            write(1 , Buffer , iRet);
        }
        printf("\n");

        close(fd);
    }

    return 0;
}


