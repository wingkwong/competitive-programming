/*
DSA Learning Series - Contest 1 - Carvans 
https://www.codechef.com/LRNDSA01/problems/CARVANS
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    int t,n; cin >> t;
    while(t--){
    	cin >> n;
    	vector<int> s(n);
    	for(int &t:s) cin >> t;
    	int ans=1;
    	for(int i=1;i<n;i++){
    		if(s[i]<s[i-1]) ans++;
    		else s[i]=s[i-1];
		}
		cout << ans << endl;
	}
    return 0;
} 
