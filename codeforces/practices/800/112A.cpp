/*
Codeforces Beta Round #85 (Div. 2 Only) - A. Bit++
https://codeforces.com/problemset/problem/112/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    string a,b;
    cin >> a >> b;
    int ans=0;
    for(int i=0;i<a.size();i++){
    	char aa=tolower(a[i]);
		char bb=tolower(b[i]);
		if(aa==bb) continue;
		else if(aa>bb) {
			ans=1; break;
		} else {
			ans=-1; break;
		}
	}
	cout << ans << "\n";
    return 0;
} 

