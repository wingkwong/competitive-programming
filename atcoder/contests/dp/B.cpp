/*
Educational DP Contest - B - Frog 2
https://atcoder.jp/contests/dp/tasks/dp_b
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
 
int main()  
{ 
    FAST_INP;
    int n, k;
    cin >> n >> k;
    vector<int> h(n), dp(n,1e9+5);
    for(int i=0;i<n;i++) cin >> h[i];
  	dp[0]=0;
  	for(int i=0;i<n;i++) { // current stone
    	for(int j=i+1;j<=i+k;j++){ // target stone
    		if(j<n){ // check if it is out of bound
    			dp[j]=min(dp[j],dp[i]+abs(h[j]-h[i])); // store min cost jumping to stone j from stone i
			}
		}
    }
  	cout << dp[n-1] << "\n";
    return 0;
} 

