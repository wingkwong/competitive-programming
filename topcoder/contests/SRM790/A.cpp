#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

// FAILED ON SYSTEM TEST
class AlicesBirthday {
	public:
	vector <int> partition(int k)
	{
	    FAST_INP;
		vl f(k);
		f[0]=f[1]=1LL;
		for(int i=2;i<k;i++){
			f[i]=f[i-1]+f[i-2];
		}
		vi ans;
		ll sum=0;
		int n=k;
		for(int i=0;i<n;i++){
			sum+=f[i];
		}
		cout << sum << endl;
		if(sum&1) {
			ans.push_back(-1);
		} else {
			ll k=sum>>1;
			bool dp[n+1][k+1];
			for(int i=0;i<=k;i++) dp[0][i]=false;
			for(int i=0;i<=n;i++) dp[i][0]=true;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=k;j++){
					dp[i][j]=dp[i-1][j];
					if(f[i-1]<=j) dp[i][j]=dp[i][j]|dp[i-1][j-f[i-1]];
				}
			}
			if(!dp[n][k]){
				ans.push_back(-1);
			} else {
				int i=n, j=k;
				while(i>0&&j>=0){
					if(dp[i-1][j]){
						i--;
						ans.push_back(i+1);
					} else if(dp[i-1][j-f[i]]){
						i--;
						j-=f[i];
					}
				}
			}
		}
//		for(auto x: ans) cout << x << endl;
	    return ans;
	}
};

//int main(){
//	AlicesBirthday c;
//	c.partition(35);
//	return 0;
//}
