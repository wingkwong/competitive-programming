/*
Codeforces Round #647 (Div. 2) - Thanks, Algo Muse! - C. Johnny and Another Rating Drop
https://codeforces.com/contest/1362/problem/C
*/
#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)


int main()  
{ 
    FAST_INP;
    int t;
	long long n;
    cin >> t;
    while(t--){
        cin >> n;
        int ans=0;
        // list out the first 16 binary numbers including 0
        // we can see the pattern for each significant bit changes
        // 1st: 0->1->0->1->0->1....			(change every 1 number)
        // 2nd: 0->0->1->1->0->0->1->1->...		(change every 2 numbers)
        // 3rd: 0->0->0->0->1->1->1->1->...		(change every 4 numbers)
        while(n){
        	ans+=n;
        	n>>=1;
		}
		cout << ans << "\n";
    }
    return 0;
} 
