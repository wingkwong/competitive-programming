/*
DSA Learning Series - Contest 1 - Coin Flip
https://www.codechef.com/LRNDSA01/problems/CONFLIP
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    int t,g,i,n,q; cin >> t;
    while(t--){
    	cin >> g;
    	while(g--){
    		cin >> i >> n >> q;
    		if(n%2==0||i==q) cout << (n/2) << endl;
    		else cout << (n/2+1) << endl;
		}
    	
	}
    return 0;
} 
