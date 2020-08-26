/*
Volume 1 - 1005. Stone Pile
https://acm.timus.ru/problem.aspx?space=1&num=1005
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;


int main()  
{ 
    FAST_INP;
    ll n, ans=100005; 
    cin >> n;
    vector<ll> w(n);
    for(auto &x:w) cin >> x;
    for(int mask=0;mask<1<<n;mask++){
    	ll w1=0, w2=0;
    	for(int i=0;i<n;i++){
    		if(mask&(1<<i)) w1+=w[i];
    		else w2+=w[i];
		}
		ans=min(ans,abs(w1-w2));
	}
	cout << ans << endl;
    return 0;
} 

