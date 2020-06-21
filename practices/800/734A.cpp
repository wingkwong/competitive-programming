/*
Codeforces Round #379 (Div. 2) - A. Anton and Danik
https://codeforces.com/problemset/problem/734/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,a=0,d=0;
    string s;
    cin >> n >> s;
    for(char c:s) {
    	if(c=='A') a++;
    	else d++;
	}
	if(d==a) cout << "Friendship" << "\n";
	else if(d>a) cout << "Danik" << "\n";
	else cout << "Anton" << "\n";
    return 0;
} 
