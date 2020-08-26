/*
AtCoder Beginner Contest 172 - B - Minor Change
https://atcoder.jp/contests/abc172/tasks/abc172_b
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    string s,t;
    cin >> s >> t;
    int n = (int)s.size();
    int ans=0;
    // choose one character of S and replace it with a different character
    for(int i=0;i<n;i++){
    	if(s[i]!=t[i]) ans++;
	}
	cout << ans << "\n";
    return 0;
} 
