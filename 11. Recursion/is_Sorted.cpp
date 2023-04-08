#include<bits/stdc++.h>
using namespace std;
bool isSorted(int arr[],int n)
{
    if(n==0||n==1)
    return true;
    if(arr[0]>arr[1])
    return false;
    return isSorted(arr+1,n-1);
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

    if(isSorted(arr,size))
        cout<<"Array is Sorted";
    else
        cout<<"Array isn't Sorted";
    return 0;
}