/*
Codeforces Round #664 (Div. 2) - Boboniu Likes to Color Balls
https://codeforces.com/contest/1395/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    #endif
    FAST_INP;
    ll t,r,g,h,w,ok;
    cin >> t;
    while(t--){
        ok=0;
        cin >> r >> g >> h >> w;
        // if there is more than 1 odd types of balls, then no solution 
        // because it has to be something like abcba or abba
        ok|=((r&1)+(g&1)+(h&1)+(w&1)<=1);
        // if three balls can be picked, pick it and add them to white balls and check again
        if(r&&g&&h) r--, g--, h--, w+=3;
        // same logic
        ok|=((r&1)+(g&1)+(h&1)+(w&1)<=1);
        cout << (ok?"Yes":"No") << endl;
    }
    return 0;
} 