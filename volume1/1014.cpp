/*
Volume 1 - 1014. Product of Digits
https://acm.timus.ru/problem.aspx?space=1&num=1014
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;


int main()  
{ 
    FAST_INP;
    ll n;
    cin >> n;
    if(n==0) {
    	cout << 10 << endl;
    	return 0;
	}
	vector<ll> v;
	function<void(ll)> build = [&](ll n) {
		if(n<10){
			v.emplace_back(n); 
			return;
		}
		for(int i=9;i>=2;i--){
			if(n%i==0){
				v.emplace_back(i);
				build(n/i);
				break;
			}
		}
	};
	build(n);
	sort(v.begin(),v.end());
	ll p=1;
	for(int i=0;i<v.size();i++) p*=v[i];
	if(p==n) {
		for(int i=0;i<v.size();i++) cout << v[i];
		cout << endl;
	}
	else cout << -1 << endl;
    return 0;
} 
