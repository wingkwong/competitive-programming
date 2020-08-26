/*
DSA Learning Series - Contest 1 - Multiple of 3   
https://www.codechef.com/LRNDSA01/problems/MULTHREE
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

bool solve() {
	ll k,d0,d1,t;
    cin >> k >> d0 >> d1;
	t = d0+d1;
	ll ans=t;
	ll sum=(2*t)%10+(4*t)%10+(8*t)%10+(6*t)%10;
	k-=2;
	if(k>0) {
		ans+=(t%10);
		k--;
	}
	ans+=(k/4)*sum;
	k%=4;
	int p=2;
	while(k--) {
		ans+=(p*t)%10;
		p=(p*2)%10;
	}
	return ((ans%3)==0);
}

int main()  
{ 
    FAST_INP;
    int t; cin >> t;
    while(t--){
    	cout << (solve()?"YES":"NO") << endl;
	}
    return 0;
} 
