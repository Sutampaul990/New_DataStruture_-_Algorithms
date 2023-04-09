#include<bits/stdc++.h>
using namespace std;
int power(int a,int b)
{
    if(b==0)
    return 1;
    return a*power(a,b-1);
}
int main()
{
    int a,b;
    cout<<"Enter a number : ";
    cin>>a;
    cout<<"Enter it's power : ";
    cin>>b;
    cout<<"Ans : "<<power(a,b)<<endl;
    return 0;
}