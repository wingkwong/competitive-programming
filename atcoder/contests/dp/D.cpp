/*
Educational DP Contest - D - Knapsack 1
https://atcoder.jp/contests/dp/tasks/dp_d
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
 
int main()  
{ 
    FAST_INP;
    ll n,W,w,v;
    cin >> n >> W;
    ll dp[W+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
    	cin >> w >> v;
    	for(int j=W;j>=w;j--){
    		dp[j]=max(dp[j],dp[j-w]+v);
		}	
	}
	cout << dp[W] << endl;
    return 0;
} 

