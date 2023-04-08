#include<bits/stdc++.h>
using namespace std;
int countDistinctWays(int nStairs) {
    //  Write your code here.
    if(nStairs<0)
        return 0;
    else if(nStairs==0)
        return 1;
    return countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<countDistinctWays(n)<<endl;
    return 0;
}
//Here the most problem is TLE Error..We can solve this using dp eaily..