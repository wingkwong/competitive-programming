/*
Educational Codeforces Round 88 (Rated for Div. 2) - A. Berland Poker
https://codeforces.com/contest/1359/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n,m,k;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        if(m==0) {
        	cout << 0 << "\n";
        	continue;
		}
        if((n/k)>=m) {
        	cout << m << "\n";
        	continue;
		}
		
		int f = n/k;
		int r = m-f;
		int p = k-1;
		
		if(p==1){
			cout << f-r << "\n";
			continue;
		}
		
		if(r<p){
			cout << f-1 << "\n";
			continue;
		}
		
		if(r%p==0) {
			cout << f-(r/p) << "\n";
			continue;
		}
		
		cout << f - ((r/p)+1) << "\n";
    }
    return 0;
} 
