/*
AtCoder Beginner Contest 174 - E - Logs
https://atcoder.jp/contests/abc174/tasks/abc174_e
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    // binary search 
    int t,n,k;
    cin >> n >> k;
    vector<ll> a(n);
    ll l=0,r=0;
    for(int i=0;i<n;i++) {
    	cin >> a[i];
    	r=max(r,a[i]);
	}
    while(l!=r){
    	int m = l+(r-l)/2;
    	ll kk=0;
		for(int i=0;i<n;i++){
			kk+=(a[i]-1)/m;
		}
    	if(res<=k) r=m;
    	else l=m+1;
	}
	cout << l << endl;
    return 0;
} 
