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
        sleep(20); // Child state SLEEP state
        printf("PID of child is : %d & PPID of child is : %d\n",getpid(), getppid());
        exit(0);
    }
    else // Parent 
    {   
        printf("Parent process is Running...\n");
        printf("PID of Parent is : %d & PPID of Parent is : %d\n",getpid(), getppid());
        exit(1);
    }

    return 0;
}