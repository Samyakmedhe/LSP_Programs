#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main()
{
    int Ret = 0 ;
    Ret = nice(0);

    printf("Current nice value : %d\n",Ret);
    
    Ret = nice(-5); // Increase priority
    
    if(Ret == -1)
    {
        printf("%s\n",strerror(errno));
    }
    printf("Current nice value : %d\n",Ret);
    return 0 ;
}