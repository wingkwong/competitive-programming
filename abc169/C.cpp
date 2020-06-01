/*
AtCoder Beginner Contest 169 - C - Multiplication 3
https://atcoder.jp/contests/abc169/tasks/abc169_c
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    long long a;
	long double b;
    cin >> a >> b;
    // multiply two numbers n truncate the fractional part
    long long ans=a*b*(long long)1;
    cout  << fixed  << ans << endl;
    return 0;
} 
