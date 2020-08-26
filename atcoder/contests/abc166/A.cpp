/*
A - A?C
https://atcoder.jp/contests/abc166/tasks/abc166_a
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    string s;
    cin >> s;
    // print ARC if it is ABC, print ABC if not
    if(s=="ABC") cout << "ARC\n";
    else cout << "ABC\n";
    return 0;
} 