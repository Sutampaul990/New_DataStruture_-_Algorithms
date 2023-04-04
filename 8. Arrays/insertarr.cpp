#include<iostream>
using namespace std;

int main()
{
    cout<<"                  Insertion in an Array                \n";
    int n,pos,value;
    cout<<"Enter the size of the array : ";
    cin>>n;
    
    if(pos<=n&&n>0){
        
        int x[n];
        cout<<"Enter the elements : \n";
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        cout<<"Enter the position : ";
        cin>>pos;
        cout<<"Enter the value : ";
        cin>>value;
        for(int i=n;i>=pos;i--)
            x[i]=x[i-1];
            x[pos-1]=value;
    
        cout<<"Here the Final Array ---\n";
        for(int i=0;i<=n;i++){
            cout<<x[i]<<"\t";
        }
        cout<<endl;
    }
    else
    cout<<"Invalid"<<endl;

    return 0;
}