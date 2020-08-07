/*
DSA Learning Series - Contest 1 - Smart Phone
https://www.codechef.com/LRNDSA01/problems/ZCO14003
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    int n,b; cin >> n;
    string s;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    ll ans=0;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
    	ans=max(ans,a[i]*(n-i));
	}
	cout << ans << endl;
    return 0;
} 
