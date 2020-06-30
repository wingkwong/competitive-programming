/*
AtCoder Beginner Contest 172 - A - Calc
https://atcoder.jp/contests/abc172/tasks/abc172_a
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int a;
    // read the input
    cin >> a;
    // print the value a+a^2+a^3
    cout << ((a) + (a*a) + (a*a*a)) << "\n";
    return 0;
} 
