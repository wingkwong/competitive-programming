/*
AtCoder Beginner Contest 171 - A - αlphabet
https://atcoder.jp/contests/abc171/tasks/abc171_a
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    char c; cin >> c;
    // If α is uppercase, print A; if it is lowercase, print a.
    if(isupper(c)) cout <<"A";
    else cout <<"a";
    return 0;
} 
