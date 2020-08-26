#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int dfs(int n, int m, int k, vector<vector<vector<long long>>>& dp){
    if(n==0) return 1;
    if(dp[n][m][k]!=0) return dp[n][m][k];
    int ans=0;
    for(int i=0;i<m;i++){
        if(m==i) continue;
        ans+=dfs(n-1,i,k,dp);
        ans%=998244353;
    }
    return dp[n][m][k] = ans;
}

int main()  
{ 
    FAST_INP;
    long long n,m,k;
    cin >> n >> m >> k;
    vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(m+1, vector<long long>(k+1,0)));
    // memset(dp,0,sizeof(dp));
    cout << dfs(n,m,k,dp) << "\n";
    return 0;
} 