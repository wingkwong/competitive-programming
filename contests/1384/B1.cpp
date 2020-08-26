/*
Codeforces Round #659 (Div. 2) - B1. Koa and the Beach (Easy Version)
https://codeforces.com/contest/1384/problem/B1
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve(){
	int n,k,l;
	cin >> n >> k >> l;
	vector<int> d(n+2,-k);
	for(int i=1;i<=n;i++) cin >> d[i];
	// pos, tide, down
	set<tuple<int,int,int>> s;
	function<bool(int, int, int)> dfs = [&](int pos, int tide, int down){
		if(pos>n) return true;
		if(s.find(make_tuple(pos,tide,down))!=s.end()) return false;
		s.insert(make_tuple(pos,tide,down));
		tide+=down?-1:1;
		// 0,1,2,…,k-2,k-1,k,k-1,k-2,...,2,1
		if(tide==0) down=0;
		if(tide==k) down=1;
		if(d[pos]+tide<=l&&dfs(pos,tide,down)) return true;
		if(d[pos+1]+tide<=l&&dfs(pos+1,tide,down)) return true;
		return false;
	};
	
	if(dfs(0,0,0)) cout << "Yes\n";
	else cout << "No\n";
}

int main()  
{ 
    FAST_INP;
    int t;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
} 


