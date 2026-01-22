#include<stdio.h>
#include<sys/mman.h>
#include<string.h>


int main()
{
    char * ptr = NULL;
    
    ptr = mmap(NULL , 4049 , PROT_READ | PROT_WRITE , MAP_PRIVATE | MAP_ANONYMOUS, -1 , 0 );

    strcpy(ptr , "Jay Ganesh....");

    printf("Data from mapped memory is : %s\n",ptr);


    return 0 ;
}