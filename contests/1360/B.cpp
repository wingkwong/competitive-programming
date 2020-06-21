/*
Codeforces Round #644 (Div. 3) - B. Honest Coach
https://codeforces.com/contest/1360/problem/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,t,s;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> x;
        // read input
        for(int i=0;i<n;i++){
			cin >> s;
			x.push_back(s);
		}
		// sort x so that we can get min diff later
		sort(x.begin(),x.end());
		int ans=INT_MAX;
		// traverse x[i] and x[i+1] where i=0...n-1
		for(int i=0;i<n-1;i++){
        	ans=min(ans,abs(x[i]-x[i+1]));
        	// if 0 is found, break eariler 
        	if(ans==0) break;
		}
		cout << ans << "\n";
    }
    return 0;
} 
