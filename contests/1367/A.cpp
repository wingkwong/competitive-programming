/*
Codeforces Round #650 (Div. 3) - A. Short Substrings
https://codeforces.com/contest/1367/problem/A
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
        // the first two characters must be same 
        string ans=s.substr(0,2);
        // travese the rest of the string
        // skip 1 character and print it
		for(int i=3;i<=s.size();i+=2){
			ans+=s[i];
		}        
		cout << ans << "\n";
    }
    return 0;
} 