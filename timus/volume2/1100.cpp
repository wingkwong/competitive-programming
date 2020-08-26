/*
Volume 2 - 1100. Final Standings
https://acm.timus.ru/problem.aspx?space=1&num=1100
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    ll n,id,m;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
    	cin >> id >> m;
    	v.push_back({id,m});
	}
	stable_sort(v.begin(), v.end(),[](const pair<int,int>& a, const pair<int,int>& b){
		return a.second>b.second;
	});
	for(auto &x:v) {
		cout << x.first << " " << x.second << endl;
	}
    return 0;
} 
