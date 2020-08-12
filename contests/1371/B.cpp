/*
Codeforces Round #654 (Div. 2) - B. Magical Calendar
https://codeforces.com/contest/1371/problem/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    long long t,n,r,ans;
    cin >> t;
    while(t--){
        cin >> n >> r;
        // When n>k, then there are k different patterns, one starting at each different day of the week. 
		// For n>r, there will never be enough days in the week for a straight line, so it's 1+2+...+r.
        if(n>r) ans=(r*(r+1))/2;
        // When n=k, you only have the straight line pattern. So for r=n, you get 1+2+...+(n-1)+1. 
        else ans=((n*(n-1))/2)+1;
        cout<<ans<<endl;
    }
    return 0;
} 
