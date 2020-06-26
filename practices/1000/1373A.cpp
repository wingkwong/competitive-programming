/*
Educational Codeforces Round 90 (Rated for Div. 2) - A. Donut Shops
https://codeforces.com/problemset/problem/1373/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t;
	long long a,b,c;
	cin >> t;
	while(t--){
		cin >> a >> b >> c;
		if(a<c) cout << "1 ";
		else cout << "-1 ";
		if(a*b>c) cout << b;
		else cout << -1;
		cout << "\n";
	}
    return 0;
} 
