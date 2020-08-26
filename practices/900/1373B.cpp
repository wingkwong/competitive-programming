/*
Educational Codeforces Round 90 (Rated for Div. 2) - B. 01 Game
https://codeforces.com/problemset/problem/1373/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t;
    string s;
    cin >> t;
    while(t--){
    	cin >> s;
    	int zero=0,one=0;
    	for(char c:s) {
    		if(c=='0') zero++;
    		else one++;
		}
		cout << (min(zero,one)&1?"DA":"NET") << "\n";
	}
    return 0;
} 
