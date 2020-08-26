/*
Educational Codeforces Round 92 (Rated for Div. 2) - A. LCM Problem
https://codeforces.com/contest/1389/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()
{
    FAST_INP;
    long long l, r, t;
    cin>>t;
    while(t--){
         cin>>l>>r;
         // if the upper number is multiple of the lower number
         // and the upper number is within [l,r]
         // then the answer exists 
         // e.g. LCM(a,b) where b is a*2 = b
         if(2*l<=r) cout<<l<<" "<<2*l<<endl;
         else cout<<-1<<" "<<-1<<endl;
    }
    return 0;
}  
