#include <stdio.h>
int fibo(int n,int a,int b)
{
    if(n>0)
    {
        printf("%d ",a);
        fibo(n-1,b,a+b);
    }
}
int main() 
{
    int n=10,a=0,b=1;
    fibo(n,a,b);
    return 0;
}