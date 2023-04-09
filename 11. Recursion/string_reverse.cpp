#include<bits/stdc++.h>
using namespace std;
void reverse_string(string &s,int i ,int j)
{
    if(i>j)
    return ;
    swap(s[i],s[j]);
    i++;
    j--;
    return reverse_string(s,i,j);
}
int main()
{
    string s = "Sutam";
    
    int i=0;
    int j=s.length()-1;
    reverse_string(s,i,j);
    cout<<s<<endl;

    return 0;
}