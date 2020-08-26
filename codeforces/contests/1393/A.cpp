/*
Codeforces Round #662 (Div. 2) - A. Rainbow Dash, Fluttershy and Chess Coloring
https://codeforces.com/contest/1393/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << n/2+1 << endl;
    }
    return 0;
} 

//-o-o
//o---
//---o
//o---
//
//xoxo
//ox-x
//x-xo
//ox-x
//
//xoxo
//oxox
//xoxo
//oxox
