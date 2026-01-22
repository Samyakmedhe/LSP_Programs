#include<stdio.h>
#include<unistd.h>


int main()
{

    int iRet = 0 ;
    iRet = truncate("Demo.txt",30);


    if(iRet == 0 )
    {
        printf("Truncate is Successfull \n");
    }
    else
    {
        printf("there is issue in Truncate\n");
    }
}