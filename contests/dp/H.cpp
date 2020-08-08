#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    int h,w;
    cin >> h >> w;
    char a[1005][1005];
    int dp[1005][1005], v[1005][1005];
    for(int i=0;i<h;i++) cin >> a[i];
	function<int(int,int)> solve = [&](int i, int j){
		// base cases
		if(i>=h||j>=w||a[i][j]=='#') return 0;
		// if this cell is visited, return dp[i][j]
		if(v[i][j]) return dp[i][j];
		// if it reaches the corner, return 1 
		if(i==h-1&&j==w-1) return dp[i][j]=1;
		// set the current cell visited
		v[i][j]=1;
		// store the recusive result with mod
		return dp[i][j]=(solve(i+1,j)+solve(i,j+1))%MOD;
	};
	cout << solve(0,0) << endl;
	return 0;
} 
