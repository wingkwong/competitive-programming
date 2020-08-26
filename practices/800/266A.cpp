/*
Codeforces Round #163 (Div. 2) - A. Stones on the Table
https://codeforces.com/problemset/problem/266/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,ans=0;
    cin >> n;
    vector<char> c(n);
    for(int i=0;i<n;i++) cin >> c[i];
    for(int i=1;i<n;i++) {
    	if(c[i]==c[i-1]) ans++;
	}
	cout << ans << "\n";
    return 0;
} 

