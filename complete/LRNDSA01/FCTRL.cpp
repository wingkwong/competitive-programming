/*
DSA Learning Series - Contest 1 - Factorial  
https://www.codechef.com/LRNDSA01/problems/FCTRL
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    int t,n; cin >> t;
    while(t--){
    	cin >> n;
    	int ans=0;
    	for(int i=5;i<=n;i*=5) ans+=n/i;
		cout << ans << endl;
	}
    return 0;
} 
