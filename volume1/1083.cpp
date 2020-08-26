/*
Volume 1 - 1083. Factorials!!!
https://acm.timus.ru/problem.aspx?space=1&num=1083
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
	string ex;
    cin >> n >> ex;
	ll k = ex.size(), ans=1;
	for(int i=n;i>=1;i-=k) ans*=i;
	cout << ans << endl;
    return 0;
} 

