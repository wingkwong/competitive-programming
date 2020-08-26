/*
Apple Division
https://cses.fi/problemset/task/1623
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // #endif
    FAST_INP;
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    ll ans=INT_MAX;
    // classic bitwise approach
	for(int mask=0;mask<(1<<n);mask++){
		ll g1=0,g2=0;
		for(int j=0;j<n;j++){
			if(mask&(1<<j)) g1+=a[j];
			else g2+=a[j];
		}
//		printf("%d %d\n", g1, g2);
		ans=min(ans,abs(g1-g2));
	}
	cout << ans << endl;
    return 0;
} 
