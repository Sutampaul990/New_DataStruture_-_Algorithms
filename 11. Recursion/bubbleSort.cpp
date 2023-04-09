#include<bits/stdc++.h>
using namespace std;
void sort_lastElemnet(int *arr,int size)
{
    
    if(size==0||size==1)
    return ;
    for(int i=0;i<size-1;i++)
        if(arr[i]>arr[i+1])
            swap (arr[i],arr[i+1]);
    sort_lastElemnet(arr,size-1);
}
int main()
{
    int arr[]={6,5,9,8,7};
    sort_lastElemnet(arr,5);
    for(int i=0;i<5;i++)
    cout<<arr[i]<<"\t";
    return 0;
}