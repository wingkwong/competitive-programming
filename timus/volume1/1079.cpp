/*
Volume 1 - 1079. Maximum
https://acm.timus.ru/problem.aspx?space=1&num=1079
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    ll a,x=1,y=2;
	vector<ll> dp(100000);
	dp[0]=0, dp[1]=1;
	for(int i=2;i<=99999;i++){
		if(i&1) dp[i]=dp[x++]+dp[y++];
		else dp[i]=dp[i/2];
	}
    while(cin>>a&&a!=0){
    	ll ans=0;
    	for(int i=0;i<=a;i++) ans=max(ans,dp[i]);
    	cout << ans << endl;
	}
    return 0;
} 

//a[0]=0
//a[1]=1
//a[2]=1
//a[3]=a[1]+a[2]=2
//a[4]=a[2]=1
//a[5]=a[2]+a[3]=3
//a[6]=a[3]=2

