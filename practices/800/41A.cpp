/*
Codeforces Beta Round #40 (Div. 2) - A. Translation
https://codeforces.com/problemset/problem/41/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    string s,t;
    cin >> s >> t;
    reverse(t.begin(),t.end());
	cout << (s==t?"YES":"NO") << "\n";
    return 0;
} 
