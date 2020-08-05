/*
Educational DP Contest - C - Vacation
https://atcoder.jp/contests/dp/tasks/dp_c
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
 
int main()  
{ 
    FAST_INP;
    int n;
    cin >> n;
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++) {
    	cin >> a[i] >> b[i] >> c[i];
	}
    // dp[i][j] means max point we can gain by doing activity j on i-th day
	int dp[n][3];
	// base cases
    dp[0][0]=a[0];
    dp[0][1]=b[0];
    dp[0][2]=c[0];
    // day 1 .. n-1
    for(int i=1;i<n;i++){
    	// do activity A + activity with max points of happiness on the previous day
    	dp[i][0]=a[i]+max(dp[i-1][1],dp[i-1][2]); 
    	// do activity B + activity with max points of happiness on the previous day
    	dp[i][1]=b[i]+max(dp[i-1][0],dp[i-1][2]); 
    	// do activity C + activity with max points of happiness on the previous day
    	dp[i][2]=c[i]+max(dp[i-1][0],dp[i-1][1]);
	}
	cout << max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    return 0;
} 

