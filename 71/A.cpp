/*
Codeforces Beta Round #65 (Div. 2)
https://codeforces.com/problemset/problem/71/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n;
    string s;
    cin >> n;
    while(n--){
    	cin >> s;
    	int k=(int)s.size();
    	if(k<=10) cout << s << "\n";
		// if its length is strictly more than 10 characters. 
        // All too long words should be replaced with a special abbreviation.
    	else cout << s[0] << k-2 << s[k-1] << "\n";
	}
    return 0;
} 

