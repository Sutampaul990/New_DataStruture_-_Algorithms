#include<bits/stdc++.h>
using namespace std;
int reverse(int n)
{
    int sum=0;
    int rem =0;
    while(n!=0)
    {
        rem = n%10;
        sum =(sum*10)+rem;
        n/=10;
    }
    return sum;
}
void say_digit(int n,string arr[])
{
    if(n==0)
    return ;
    int digit = n%10;
    cout<<arr[digit]<<"\t";
    say_digit(n/10,arr);
}
int main()
{
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cin>>n;
    n=reverse(n);
    say_digit(n,arr);
    return 0;
}