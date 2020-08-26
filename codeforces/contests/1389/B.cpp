/*
Educational Codeforces Round 92 (Rated for Div. 2) - B. Array Walk
https://codeforces.com/contest/1389/problem/B 
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
long long n,k,z;
long long dp[100005][6];
long long solve(vector<long long>& a, int idx, int kk, int zz) {
	// base case
    if(idx>=n||kk==0||idx<0) return 0;
    // if the result has been calculated, return it immediately
    if(dp[idx][zz]!=-1) return dp[idx][zz];
    long long val = 0;
    // move right
    if(idx<n) val=max(val,(a[idx]+solve(a,idx+1,kk-1,zz)));
    // move left
    if(idx>=0&&zz>0) val=max(val,(a[idx]+solve(a,idx-1,kk-1,zz-1)));
    return dp[idx][zz]=val;
}

int main() {
    FAST_INP;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k >> z;
		vector <long long> a(n);
		memset(dp,-1,sizeof(dp));
        for (int i=0;i<n;i++) cin >> a[i];
        cout << a[0] + solve(a,1,k,z) << "\n";
    }
}
