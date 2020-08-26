/*
Volume 1 - 1009. K-based Numbers
https://acm.timus.ru/problem.aspx?space=1&num=1009
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;


int main()  
{ 
    FAST_INP;
    ll n, k;
    cin >> n >> k;
    int dp[n+1][2]; // check if the first digit is 0 or 1 in a n-th digit number
    dp[1][0]=1, dp[1][1]=k-1;
    for(int i=2;i<=n;i++){
    	dp[i][0]=dp[i-1][1];
    	dp[i][1]=dp[i-1][0]*(k-1)+dp[i-1][1]*(k-1);
	}
    printf("%d\n", dp[n][1]);
    return 0;
} 
