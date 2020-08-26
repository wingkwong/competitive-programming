/*
Codeforces Round #658 (Div. 2) - C1 - Prefix Flip (Easy Version)
https://codeforces.com/contest/1382/problem/C
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,t;
    cin >> t;
    while(t--){
        cin >> n;
        string s1,s2;
        cin >> s1 >> s2;
        vector<int> ans;
        for(int i=0;i<n;i++){
        	if(s1[i]!=s2[i]){
        		// approach: flip the bit one by one
        		// e.g. flip z
				// (x..y)(z)      invert and flip (x..y)(z) 
				// (!z)(!y..!x)   invert and flip (z)
				// (z)(!y..!x)    invert and flip (!y..!x)
				// (x..y)(!z)	  
        		if(i) ans.emplace_back(i+1);
        		ans.emplace_back(1);
        		if(i) ans.emplace_back(i+1);
			}
		}
		cout << ans.size() << endl;
		for(auto k:ans) cout << k << " ";
		cout << endl;
    }
    return 0;
} 
