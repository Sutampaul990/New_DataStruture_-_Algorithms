#include<bits/stdc++.h>
#include<stack>
using namespace std;

int main()
{
    string s;
    int i=0;
    stack<char>st;

    cout<<"Enter any words : ";
    cin>>s;

    while(s[i]!='\0')
    {
        st.push(s[i]);
        i++;
    }
    cout<<"After Reverse : ";
    while(!st.empty())
    {
        
        cout<<st.top();
        st.pop();
    }

    return 0;
}