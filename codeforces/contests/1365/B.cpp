/*
Codeforces Round #648 (Div. 2) - B. Trouble Sort
https://codeforces.com/contest/1365/problem/B
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
        cin >> n;
        vector<int> a(n+1),b(n+1);
    	bool s=1, zero=0, one=0;
        for(int i=1;i<=n;i++){
        	cin >> a[i];
        	if(i>=2&&a[i]<a[i-1]) {
        		s=0;
			}
        	
		}
		for(int i=1;i<=n;i++){
        	cin >> b[i];
        	if(b[i]==0) zero=1;
        	else one=1;
		}
		// if we have 0 and 1, we can use it to rearrange for all positions
		if(zero&&one) cout << "Yes\n";
		// if it is sorted already, no operation is needed. 
		else if(s) cout << "Yes\n";
		// if not, it is not possible to sort
		else cout << "No\n";
    }
    return 0;
} 
