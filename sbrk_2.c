#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
    void *current_break = NULL;
    void *newbreak = NULL;

    current_break = sbrk(0);
    printf("Current proccess break %p\n",current_break);

    newbreak = sbrk(100);
    
    strcpy((char *) newbreak , "Jay Ganesh...");

    printf("Data from new memmory : %s\n",(char * )newbreak);

    sbrk(-100);
    
    return 0;
}