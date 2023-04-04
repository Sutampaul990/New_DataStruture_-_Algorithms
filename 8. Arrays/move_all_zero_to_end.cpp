#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of the Array : ";
    cin>>n;
    int a[n],c=0;
    cout<<"Enter the Elements : ";
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=0){
            cout<<a[i]<<"\t";
            c++;
        }
    }
    for(int i=n;i>c;i--){
        a[i]=0;
        cout<<a[i]<<"\t";
    }


    return 0;
}