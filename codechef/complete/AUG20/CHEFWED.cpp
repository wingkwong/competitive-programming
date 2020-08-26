/*
August Challenge 2020 Division 2  - Chef and Wedding Arrangements
https://www.codechef.com/AUG20B/problems/CHEFWED
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;
const int mxN = 1005;

int main(){
	FAST_INP;
	int t,n,k;
	cin >> t;
	while(t--){
	    cin >> n >> k;
        vector<int> f(mxN), dp(mxN,1e9), cnt(mxN);
        for(int i=0;i<n;i++) cin >> f[i];
        dp[0]=0;
        for(int i=0;i<n;i++){
            fill(cnt.begin(),cnt.end(),0);
            for(int j=i;j<n;j++){
                cnt[f[j]]++;
                int g=0;
                for(int x=1;x<=100;x++){
                    g+=cnt[x]==1?0:cnt[x];
                }
                dp[j+1]=min(dp[i]+g+k, dp[j+1]);
            }        
        }
        cout << dp[n] << "\n";
	}
	return 0;
}