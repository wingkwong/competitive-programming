/*
Codeforces Round #644 (Div. 3) - C. Similar Pairs
https://codeforces.com/contest/1360/problem/C
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n,a;
    bool f;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> x;
		int even=0,odd=0;
        for(int i=0;i<n;i++){
        	cin >> a;
        	if(a%2==0) even++;
			else odd++;
        	x.push_back(a);
		}
		sort(x.begin(),x.end());
		// since x%2 must be 0
		// if even%2==0, a partition must exist
		if(even%2==0) cout << "YES\n";
		else {
			f=false;
			for(int i=0;i<x.size()-1;i++){
				// traverse each element (i=0..n-1) to check if the absolute diff between x[i] and x[i+1] is 1 or not
				if(x[i]%2!=x[i+1]%2&&abs(x[i]-x[i+1])==1){
					f=true;
					break;
				}
			}
			if(f) cout << "YES\n";
			else cout << "NO\n";
		}
    }
    return 0;
} 
