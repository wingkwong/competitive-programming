/*
Volume 2 - 1110. Power
https://acm.timus.ru/problem.aspx?space=1&num=1110
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

ll modpow(ll base, ll exp, ll mod) {
  base%=mod;
  ll res=1;
  while(exp>0) {
    if (exp&1) res=(res*base)%mod;
    base=(base*base)%mod;
    exp>>=1;
  }
  return res;
}

int main()  
{ 
    FAST_INP;
    ll n,m,y;
    cin >> n >> m >> y;
    vector<int> v;
    for(int i=0;i<m;i++){
    	if(modpow(i,n,m)==y) v.emplace_back(i);
	}
	if(v.size()==0) cout << -1 << endl;
	else {
		for(auto x:v) cout << x << " ";
		cout << endl;
	}
    return 0;
} 
