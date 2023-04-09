#include<stdio.h>

int fib(int n) 
{
    if(n==0||n==1)
    return n;
    return fib(n-1)+fib(n-2);
}
int main()
{
    int n;
    printf("Enter the last term of the series : ");
    scanf("%d",&n);
    printf("So the Result : \n");
    printf("%d",fib(n));
    return 0;
}