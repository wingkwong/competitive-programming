/*
Codeforces Round #663 (Div. 2) - B. Fix You
https://codeforces.com/contest/1391/problem/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

// I misread the question ...
// -----------------------------------------
//		int ans=INT_MAX;
//		function<void(int,int,int)> dfs = [&](int i, int j, int cnt)
//		{
//		  if(i>=n||i<0||j>=m||j<0) return;
//		  if(i==0&&j==0) {
//		  	ans=min(ans,cnt);
//		  	return;
//		  }
//		  dfs(i-1,j,cnt+(i>0&&a[i-1][j]=='R'?1:0));
//		  dfs(i,j-1,cnt+(j>0&&a[i][j-1]=='D'?1:0));
//		};
//		
//		dfs(n-1,m-1,0);

int main()  
{ 
    FAST_INP;
    int t,n,m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<string> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        int ans=0;
        // count 'D' in the last row and 'R' in the last col
        // the rest of them don't matter because it will go to the last row or the last col eventually
		for(int i=0;i<n-1;i++) ans+=a[i][m-1]=='R';
		for(int i=0;i<m-1;i++) ans+=a[n-1][i]=='D';
		cout << ans << endl;
    }
    return 0;
} 
