#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int s,int e)
{
    int count=0;
    int pivot = arr[s];
    for(int i=s+1;i<=e;i++)
    {
        if(pivot>=arr[i])
            count++;
    }
    int pivotIndex = s+count;
    swap(arr[s],arr[pivotIndex]);
    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex)
    {
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex&&j>pivotIndex)
        swap(arr[i++],arr[j--]);
    }
    return pivotIndex;
}
void quickSort(int arr[],int s,int e)
{
    if(s>=e)
    return;
    //Partition
    int p=partition(arr,s,e);
    //for the left part
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}
int main()
{
    int arr[]={1,5,8,2,0};
    int n=5;
    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
    return 0;
}