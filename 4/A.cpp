/*
Codeforces Beta Round #4 (Div. 2 Only) - A. Watermelon
https://codeforces.com/problemset/problem/4/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int w;
    cin >> w;
    // Print YES, if the boys can divide the watermelon into two parts, 
    // each of them weighing even number of kilos; and NO in the opposite case.
    if(w==2||w%2) cout << "NO";
    else cout << "YES";
    return 0;
} 
