/*
Codeforces Round #652 (Div. 2) - A. FashionabLee
https://codeforces.com/contest/1369/problem/A
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
    	cout << (n%4==0?"YES":"NO") << "\n";
	}
    return 0;
} 
