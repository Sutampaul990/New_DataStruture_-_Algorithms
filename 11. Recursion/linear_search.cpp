#include<bits/stdc++.h>
using namespace std;
bool linear_Search(int arr[],int n,int key)
{
    if(n==0)
    return false;
    if(arr[0]==key)
    return true;
    return linear_Search(arr+1,n-1,key);
}
int main()
{
    int arr[10];
    int size,key;
    cout<<"Enter the size : ";
    cin>>size;
    cout<<"Enter the elements : ";
    for(int i=0;i<size;i++)
    cin>>arr[i];
    cout<<"Enter the element you want to search : ";
    cin>>key;
    //print
    if(linear_Search(arr,size,key))
        cout<<"Found";
    else
        cout<<"Not Found";
    return 0;
}