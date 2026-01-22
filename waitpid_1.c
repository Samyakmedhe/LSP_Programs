#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t childpid = 0;
    pid_t Ret = 0;
    int status = 0 ;

    childpid = fork();

    if(childpid ==  0 )
    {
        printf("Child is running wait pid : %d\n",getpid());
        sleep(10);
        printf("Child process exiting...\n");
        exit(11);
    }
    else
    {   
        printf("Parent is running...\n");
        printf("Parent is Waiting for child : %d\n",childpid);

        Ret = waitpid(childpid, &status , 0);
        if(WIFEXITED(status))
        {
            printf("child exited with PID : %d\n",Ret);
            printf("Exit Status of child is : %d\n",WEXITSTATUS(status));
        }
    }


    return 0;
}