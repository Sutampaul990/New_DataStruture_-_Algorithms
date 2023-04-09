#include <bits/stdc++.h> 
using namespace std;
bool palin(string s,int i,int j){
    if(i>j)
        return true;
    
    if(s[i]!=s[j])
        return false;
    
    return palin(s,i+1,j-1);
}
bool checkPalindrome(long long N)
{
	// Write your code here.
    string s="";
  
  	while(N!=1){
      	int rem=N%2;
     	s=s+to_string(rem);
      	N=N/2;
      	if(N==1)
           s=s+to_string(1);
  	}
    
    if(palin(s,0,s.length()-1))
        return true;
    else
        return false;
}
int main()
{
    long long n;
    cout<<"Enter any number : ";
    cin>>n;
    
    if(checkPalindrome(n))
    cout<<"True";
    else
    cout<<"False";
    return 0;
}