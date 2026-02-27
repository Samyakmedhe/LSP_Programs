//          ./lsx      
//          argv[0]    
//          argc = 1

/*
    Step 1 : 
        Open the Current Directory (".")
    
    Step 2 :
        Read All entry from that directory

    Step 3 :
        print the name of files

    Step 4 :
        close the directory 

*/


#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc , char * argv[])
{
    char * path = ".";
    
    DIR *dp = NULL;

    dp = opendir(path);
    if(dp == NULL)
    {
        printf("ERROR : Unable to open directory\n");
        return -1;
    }

    struct dirent *dobj;

    while((dobj = readdir(dp)) != NULL)
    {
        printf("%s\t",dobj->d_name);
    }
    printf("\n");
    closedir(dp);

    return 0;
}