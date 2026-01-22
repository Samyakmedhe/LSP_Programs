
// OUTPUT Depends on Scheduling

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{

    pid_t pid = 0;

    pid = fork();

    if(pid == 0) // child 
    {
        printf("Child process is Running...\n");
        printf("PID of child is : %d & PPID of child is : %d\n",getpid(), getppid());
    }
    else // Parent 
    {   
        printf("Parent process is Running...\n");
        printf("PID of Parent is : %d & PPID of Parent is : %d\n",getpid(), getppid());
    }

    return 0;
}