/*
AtCoder Beginner Contest 174 - B - Distance
https://atcoder.jp/contests/abc174/tasks/abc174_b
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
	FAST_INP;
	ll n,d,x,y;
	cin >> n >> d;
	int ans=0;
	for (int i=0; i<n; i++) {
		cin >> x >> y;
		if(x*x+y*y<=d*d) ans++;
	}
	cout << ans << endl;
    return 0;
} 
