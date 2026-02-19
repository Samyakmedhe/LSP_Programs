#include<stdio.h>


int main(int argc , char * argv[])
{
    printf("Number of Commandline argument are : %d\n",argc);

    if(argc != 5)
    {
        printf("Unable to proceed as invalid number of argument\n");
        printf("Please provide : \n");
        printf("IP Address\nPort Number\nTargeted file name\nNew file name\n");
        return -1;
    }
    printf("Excutable name : %s\n",argv[0]);
    printf("IP Address : %s\n",argv[1]);
    printf("Port number : %s\n",argv[2]);
    printf("Targeted file : %s\n",argv[3]);
    printf("New file : %s\n",argv[4]);

    return 0;
}