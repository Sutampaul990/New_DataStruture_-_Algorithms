#include<bits/stdc++.h>
using namespace std;
int powerof2(int pow)
{
    if(pow==0)
    return 1;
    else if(pow==1)
    return 2;
    return 2*powerof2(--pow);
}
int main()
{
    int pow;
    cin>>pow;
    if(pow>=0)
    cout<<powerof2(pow)<<endl;
    else
    cout<<"Not Exist"<<endl;
    return 0;
}