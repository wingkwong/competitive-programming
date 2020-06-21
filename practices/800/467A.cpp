/*
Codeforces Round #267 (Div. 2) - A. George and Accommodation
https://codeforces.com/problemset/problem/467/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,p,q,ans=0;
    cin >> n;
    while(n--){
    	cin >> p >> q;
    	if(q-p>=2) ans++;
	}
	cout << ans << "\n";
    return 0;
} 
