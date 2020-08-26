/*
Volume 1 - 1025. Democracy in Danger
https://acm.timus.ru/problem.aspx?space=1&num=1025
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    ll k,ans=0;
    cin >> k;
    vector<ll> a(k);
	for(auto &x:a) cin >> x;
	sort(a.begin(),a.end());
	for(int i=0;i<(k+1)/2;i++) ans+=(a[i]+1)/2;
	cout << ans << endl;
    return 0;
} 


