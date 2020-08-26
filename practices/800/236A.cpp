/*
Codeforces Round #146 (Div. 2) - A. Boy or Girl
https://codeforces.com/problemset/problem/236/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    string s;
    cin >> s;
    unordered_set<char> ss;
    for(char c:s) ss.insert(c);
	cout << (ss.size()&1?"IGNORE HIM!":"""CHAT WITH HER!") << "\n";
    return 0;
} 
 
