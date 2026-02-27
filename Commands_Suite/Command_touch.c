//          ./touchx       File Name 
//          argv[0]         argv[1]         
//          argc = 2

/*
    Step 1 : 
        Accept file from command line
    
    Step 2:
        Check weather file is existing or not

    Step 3 :
        If it is Existing return
    
    Step 4 :
        If it is not then create file
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
        printf("Use command as :    ./touchx   FileName  \n");

        return 1;
    }

    if(access(argv[1], F_OK) == 0 )
    {
        return 0;
    }
    else
    {
        creat(argv[1], 0777);
    }

    return 0;
}