/*
Volume 1 - 1001. Reverse Root
https://acm.timus.ru/problem.aspx?space=1&num=1001
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    ll a;
	vector<ll> v;
    while(cin>>a) v.emplace_back(a);
    for(int i=v.size()-1;i>=0;i--) cout << setprecision(4) << fixed << sqrt(v[i]) << endl;
    return 0;
} 
