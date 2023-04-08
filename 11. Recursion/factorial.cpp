#include<bits/stdc++.h>
using namespace std;
int fibo(int n)
{
    if(n==0||n==1)
    return 1;
    return n*fibo(n-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<fibo(n)<<endl;
    return 0;
}