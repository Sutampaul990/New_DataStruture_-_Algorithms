#include<bits/stdc++.h>
using namespace std;
bool binarSearch(int *arr,int s,int e,int key)
{
    if(s>e)
    return false;
    int mid = s+(e-s)/2;
    if(arr[mid]>key)
    return binarSearch(arr,s,e=mid-1,key);
    else if(arr[mid]<key)
    return binarSearch(arr,s=mid+1,e,key);
    if(arr[mid]==key)
    return true;
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
    int s=0,e=size-1;
    //Print
    if(binarSearch(arr,s,e,key))
        cout<<"Found";
    else
        cout<<"Not Found";
    return 0;
}