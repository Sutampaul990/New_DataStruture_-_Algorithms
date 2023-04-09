#include<bits/stdc++.h>
using namespace std;
bool pal_str(string str,int i,int j)
{
    if(i>j)
    return true;
    if(str[i]!=str[j])
    return false;
    return pal_str(str,i+1,j-1);
}
int main()
{
    string s = "abbcbba";
    if(pal_str(s,0,s.length()-1))
        cout<<"It is a Palindrome";
    else
        cout<<"It is not a Palindrome";
    return 0;
}