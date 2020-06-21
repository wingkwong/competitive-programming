/*
A - Registration
https://atcoder.jp/contests/abc167/tasks/abc167_a
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    string s,t;
    cin >> s >> t;
    int ans=0;
    // the length of t = the length of s + 1
    // iterate 0..the length of t - 1 / the length of s
    for(int i=0;i<t.size()-1;i++){
        // compare both character in S[i] and S[t] to see if they fare same
        if(s[i]==t[i]) ans++;
    }
    // if all are same, return Yes
    if(ans==t.size()-1) cout << "Yes\n";
    // if not, return No
    else cout << "No\n";
    return 0;
} 