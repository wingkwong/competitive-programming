/*
Educational DP Contest - G - Longest Path
https://atcoder.jp/contests/dp/tasks/dp_g
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 

int main()  
{ 
    FAST_INP;
    int n,m,x,y;
    cin >> n >> m;
	vector<int> dp(n+1,0); 
	vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
    	cin >> x >> y;
    	// g does not contain directed cycles
    	g[x].push_back(y);
	}
	// traverse each node and count the path
	// use dp[from] to store the result and use it directly next time if necessary 
	function<int(int)> solve = [&](int from) {
		if(dp[from]) return dp[from];
		int ans=0;
		for(int to:g[from]){
			ans=max(ans,solve(to)+1);
		}
		return dp[from]=ans;	
	};
	int ans=0;
	for(int i=0;i<n;i++){
		// start from 1
		ans=max(ans,solve(i+1));
	}
	cout << ans << endl;
    return 0;
} 
