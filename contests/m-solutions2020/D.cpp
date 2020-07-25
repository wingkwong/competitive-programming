/*
M-SOLUTIONS Programming Contest 2020 - D - Road to Millionaire
https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_d
*/

#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    ll ans = 1000;
    for(int i=0;i<n-1;i++){
    	// greedy - buy low sell high
    	ll stock=0;
    	if(a[i]<a[i+1]) stock = ans/a[i];
    	ans+=(a[i+1]-a[i])*stock;
	}
	cout << ans << endl;
    return 0;
} 
