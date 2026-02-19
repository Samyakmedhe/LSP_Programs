#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("PID of running process : %d\n",getpid());

    printf("PID of Parent running process : %d\n",getppid());
        


    return 0;
}