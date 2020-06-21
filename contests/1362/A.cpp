/*
Codeforces Round #647 (Div. 2) - Thanks, Algo Muse! - A. Johnny and Ancient Computer
https://codeforces.com/contest/1362/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

long long solve(long long a, long long b){
	int ans=0;
	// multiply a by 8, 4, and 2 to see if a can be b or not
	// if so, print the number of operations
	// else, print -1
	while(a*8<=b) {
		ans++;
		a*=8;
	}
	while(a*4<=b) {
		ans++;
		a*=4;
	}
	while(a*2<=b) {
		ans++;
		a*=2;
	}	
	
	if(a==b){
		cout << ans << "\n";
	} else {
		cout << -1 << "\n";
	}
}

int main()  
{ 
    FAST_INP;
    int t;
    long long a,b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        // if a==b, no operation
        if(a==b) {
        	cout << 0 << "\n";
        	continue;
		}
		// by arranging the order, we only need to take care of 3 operations
        solve(min(a,b), max(a,b));
    }
    return 0;
} 
