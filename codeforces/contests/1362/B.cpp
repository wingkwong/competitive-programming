/*
Codeforces Round #647 (Div. 2) - Thanks, Algo Muse! - B. Johnny and His Hobbies
https://codeforces.com/contest/1362/problem/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n;
    cin >> t;
    while(t--){
    	// brute force approach
    	int ans=-1;
        cin >> n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        // sort input 
        sort(a.begin(),a.end());
        for(int i=1;i<1024;i++){
        	int f=true;
        	// calculate each possible value
        	for(int j=0;j<n;j++){
        		b[j]=a[j]^i;
			}
			// sort XOR result array
        	sort(b.begin(),b.end());
        	// if they are not same, the current i is not the correct answer
			for(int i=0;i<n;i++){
				if(a[i]!=b[i]){
					f=false;
					break;
				}
			}
			// if the ans is found, skip the rest of the operations
			if(f){
				ans=i;
				break;
			} 
		}
		if(ans) cout << ans << "\n";
		else cout << -1 << "\n";
    }
    return 0;
} 
