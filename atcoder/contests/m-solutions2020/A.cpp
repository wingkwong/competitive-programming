/*
M-SOLUTIONS Programming Contest 2020 - A - Kyu in AtCoder
https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_a
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t; 
    cin >> t;
    // straightforward .. follow the Problem Statement
    if(t>=400&&t<=599) cout << 8;
    else if(t>=600&&t<=799) cout << 7;
    else if(t>=800&&t<=999) cout << 6;
    else if(t>=1000&&t<=1199) cout << 5;
    else if(t>=1200&&t<=1399) cout << 4;
    else if(t>=1400&&t<=1599) cout << 3;
    else if(t>=1600&&t<=1799) cout << 2;
    else if(t>=1800&&t<=1999) cout << 1;
    return 0;
} 
