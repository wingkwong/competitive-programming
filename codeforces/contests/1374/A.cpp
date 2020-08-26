/*
Codeforces Round #653 (Div. 3) - A. Required Remainder
https://codeforces.com/contest/1374/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve(){
    int x,y,n;
	cin >>x>>y>>n;
	// if n%x is y, print n 
	if(n%x==y) cout << n << "\n";
	// if k%x is less than y, e.g. 12345%7=4 but we need 5
	// in this case, the max k would be in the previous cycle 
	// n - (n%x) - (x-y) 
	// (n%x) : reach to a point where the remainder is 0
	// (x-y) : reach to the target y
    else if(n%x<y) cout << (n-(n%x)-(x-y)) << "\n";
    // if it is still in the cycle, simply deduct n by ((n%x)-y)
    else cout << (n-((n%x)-y)) << "\n";
} 

int main()  
{ 
    FAST_INP;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
} 
