#include<bits/stdc++.h>
using namespace std;
void mergeTwoarr(int *arr,int s,int e)
{
    int mid = s+(e-s)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    int k=s;

    for(int i=0;i<len1;i++)
        arr1[i]=arr[k++];
    
    k=mid+1;
    for(int i=0;i<len2;i++)
        arr2[i]=arr[k++];

    int i=0,j=0;
    k=s;

    while(i<len1 && j<len2)
    {
        if(arr1[i]<arr2[j])
        arr[k++]=arr1[i++];
        else
        arr[k++]=arr2[j++];
    }
    while(i<len1){
        arr[k++]=arr1[i++];
    }

    while(j<len2){
        arr[k++]=arr2[j++];
    }
    delete []arr1;
    delete []arr2;
}
void mergeSort(int *arr,int s,int e)
{
    if(s>=e)
    return;
    int mid = s+(e-s)/2;
    //For the Left Part
    mergeSort(arr,s,mid);
    //For the Right part
    mergeSort(arr,mid+1,e);
    //Merge two Sorted Arrays
    mergeTwoarr(arr,s,e);
}
int main()
{
    int arr[]={6,5,8,9,1,10,4,3,2,0};
    int n=10;
    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
    return 0;
}