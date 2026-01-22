#include<stdio.h>
#include<unistd.h>



int main()
{
    int Ret = 0 ;
    Ret = nice(0);

    printf("Current nice value : %d\n",Ret);
    

    return 0 ;
}