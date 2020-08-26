/*
Codeforces Round #661 (Div. 3) - C. Boats Competition
https://codeforces.com/contest/1399/problem/C
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

// WA
//int solve(vector<int>& a, int n){
//	unordered_map<int,int> m;
//	int max_cnt=0;
//	for(int i=0;i<n-1;i++){
//		for(int j=i+1;j<n;j++){
//			m[a[i]+a[j]]++;
//			max_cnt=max(m[a[i]+a[j]],max_cnt);
//		}
//	}
//	int sum=0;
//	vector<int> q;
//	for(auto x:m){
//		if(max_cnt==x.second){
//			sum=x.first;
//			q.emplace_back(x.first);
//		}
//		printf("%d %d\n", x.first, x.second);
//	}
//	int ans=0;
//	for(auto k: q){
//		vector<int> v(n,0);
//		int cnt=0;
//		for(int i=0;i<n-1;i++){
//			if(v[i]) continue;
//			for(int j=i+1;j<n;j++){
//				if(!v[j]&&(a[i]+a[j]==k)){
//					cnt++;
//					v[j]=1;
//					break;
//				}
//			}
//		}
//		ans=max(ans,cnt);
//	}
//	return ans;
//}

int solve(vector<int>& a, int n){
	int ans=0;
	// let i be the total weight
	for(int i=2;i<=n*2;i++){
		vector<int> c(n*2,0);
		int cnt=0;
		for(int k:a){
			// if the total weight > current weight
			// and a pair can be made
			if(i>k&&c[i-k]){
				c[i-k]--;
				cnt++;
			}else{
				// increase c[k] by 1 to wait for the pair
				c[k]++;
			}
		}
		ans=max(ans,cnt);
	}
	return ans;
}

int main()  
{ 
    FAST_INP;
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        cout << solve(a,n) << endl;
    }
    return 0;
} 
