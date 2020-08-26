/*
Codeforces Round #661 (Div. 3) - B. Gifts Fixing
https://codeforces.com/contest/1399/problem/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n),b(n);
        int min_a=1e9+5,min_b=1e9+5;
        // read candy n find the min number of candy 
        for(int i=0;i<n;i++) {
        	cin >> a[i];
        	min_a=min(min_a,a[i]);
		}
        // read orange  n find the min number of orange  
        for(int i=0;i<n;i++) {
        	cin >> b[i];
        	min_b=min(min_b,b[i]);
		}
		ll ans=0;
		for(int i=0;i<n;i++){
			// calculate how many operations we need for each gift
			// if we take the max from a and b, the other one must be also covered
			ans+=max(a[i]-min_a, b[i]-min_b);
			// the logic can be also implemented as below
			/*
			if(a[i]==min_a&&b[i]==min_b) continue;
			else if(a[i]==min_a&&b[i]>min_b) ans+=b[i]-min_b;
			else if(b[i]==min_b&&a[i]>min_a) ans+=a[i]-min_a;
			else if(a[i]>min_a&&b[i]>min_b){
				if(a[i]-min_a < b[i]-min_b) {
					ans+=a[i]-min_a;
					ans+=b[i]-min_b-(a[i]-min_a);
				} else {
					ans+=b[i]-min_b;
					ans+=a[i]-min_a-(b[i]-min_b);
				}
			}
			*/
		}
		cout << ans << endl;
    }
    return 0;
} 
