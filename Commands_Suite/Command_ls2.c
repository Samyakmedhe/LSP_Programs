//          ./lsx     -i            
//          argv[0]    argv[1]  
//          argc = 2

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
    int Option = 0;
    // 1 : ls -a
    // 2 : ls -i

    if(argc == 1)
    {
        Option = 1;
    }
    else if(strcmp (argv[1], "-a") == 0 )
    {
        Option = 1;
    }
    else if(strcmp (argv[1], "-i") == 0 )
    {
        Option = 2;
    }
    else
    {
        printf("ERROR : There is no such option\n");
        return -1;
    }

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
        if(Option == 1)
        {
            printf("%s\t",dobj->d_name);
        }    
        else if(Option == 2)
        {
            printf("%llu\t%s\t\n",dobj->d_ino, dobj->d_name);
        }
    }
    printf("\n");
    closedir(dp);

    return 0;
}