#include<iostream>
using namespace std;


int main()
{
    int n,count1=0,count2=0;
    cout<<"Enter the size : ";
    cin>>n;
    if(n==0)
    cout<<"Don't be oversmart.Please enter right input....\n";
    else{
    int arr[n];
    cout<<"Enter the Elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]%2!=0)
            count1++;
        else
            count2++;
    }
    cout<<"Odd numbers : "<<count1;
    cout<<"\nEven numbers : "<<count2;
    }
    return 0;
}