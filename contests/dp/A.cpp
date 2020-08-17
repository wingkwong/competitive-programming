/*
Educational DP Contest - A - Frog 1
https://atcoder.jp/contests/dp/tasks/dp_a
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
 
int main()  
{ 
    FAST_INP;
    int n;
    cin >> n;
    vector<int> h(n), dp(n);
    for(int i=0;i<n;i++) cin >> h[i];
  	dp[0]=0;
  	dp[1]=abs(h[1]-h[0]);
  	for(int i=2;i<n;i++) {
        // dp[i] stores the minimum possible cost incurred
        // as the frog can only jump to Stone i + 1 or Stone i + 2 
        // take the min of dp[i-1]+ cost of | h(i)-h(j-1) | and dp[i-2] + cost of | h(i)-h(j-2) |
    	dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
    }
  	cout << dp[n-1] << "\n";
    return 0;
} 

