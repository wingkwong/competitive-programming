/*
Codeforces Round #172 (Div. 2) - A. Word Capitalization
https://codeforces.com/problemset/problem/281/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    string s;
    cin >> s;
    s[0]=toupper(s[0]);
	cout << s << "\n";
    return 0;
} 

