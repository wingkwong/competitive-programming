/*
Volume 2 - 1196. History Exam
https://acm.timus.ru/problem.aspx?space=1&num=1196
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    ll n,m,x;
    cin >> n;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++) {
    	cin >> x;
    	mp[x]++;
	}
	cin >> m;
	ll ans=0;
	for(int i=0;i<m;i++) {
    	cin >> x;
    	if(mp[x]) ans++;
	}
	cout << ans << endl;
    return 0;
} 
