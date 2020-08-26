/*
Educational DP Contest - F - LCS
https://atcoder.jp/contests/dp/tasks/dp_f
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
 
int main()  
{ 
    FAST_INP;
    string s,t;
    cin >> s >> t;
    int m=s.size(), n=t.size();
	// dp[m][n] : length of LCS 
	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
    	for(int j=1;j<=n;j++){
    		if(s[i-1]==t[j-1]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
    		else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	// building LCS
	string ans="";
	int i=m, j=n;
	while(i&&j){
		if(dp[i][j]==dp[i-1][j]) i--;
		else if(dp[i][j]==dp[i][j-1]) j--;
		else {
			ans=s[i-1]+ans;
			i--, j--;	
		}
	}
	cout << ans << endl;
    return 0;
} 

