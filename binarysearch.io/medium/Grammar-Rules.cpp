#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int mod=1e9+7;
    map<char, string> m;
    vector<vector<int>> dp;
    int dfs(int n, char from){
        if(n==0) return 1;
        if(dp[n][from-'a']) return dp[n][from-'a'];
        long ans=0;
        for(char c: m[from]) ans+=dfs(n-1,c);
        return dp[n][from-'a']=ans%mod;
    }
    int solve(int n) {
        if(n==0) return 0;
        dp.resize(n+1,vector<int>(26,0));
        m['a']="e";
        m['e']="ai";
        m['i']="aeou";
        m['o']="iu";
        m['u']="a";
        m['z']="aeiou";
        return dfs(n,'z');
    }
};
