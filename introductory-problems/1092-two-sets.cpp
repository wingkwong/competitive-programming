/*
Two Sets
https://cses.fi/problemset/task/1092
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // #endif
    FAST_INP;
    ll n;
    cin >> n;
    ll sum = n*(n+1)/2;
    if(sum&1){
    	// no solution for odd sum
    	cout << "NO" << endl;
	}else{
    	cout << "YES" << endl;
		vector<ll> a,b;
		// the sum of both set would be sum/2
		ll half=sum/2LL;
		while(n){
			// split into two sets
			if(half>=n) {
				a.emplace_back(n);
				half-=n;
			}
			else b.emplace_back(n);
			n--;
		}
		cout << a.size() << endl;
		for(ll &x:a) cout << x << " ";
		cout << endl;
		cout << b.size() << endl;
		for(ll &x:b) cout << x << " ";
		cout << endl;
	}
    return 0;
} 
