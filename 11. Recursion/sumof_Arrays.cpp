#include<bits/stdc++.h>
using namespace std;
int sumofArray(int arr[],int n)
{
    if(n==0)
    return 0;
    
    return arr[0]+sumofArray(arr+1,n-1);
}
int main()
{
    int arr[10];
    int size;
    cout<<"Enter the size : ";
    cin>>size;
    cout<<"Enter the elements : ";
    for(int i=0;i<size;i++)
    cin>>arr[i];
    cout<<sumofArray(arr,size)<<endl;
    return 0;
}