/*
Codeforces Round #664 (Div. 2) - B. Boboniu Plays Chess
https://codeforces.com/contest/1395/problem/B
*/


#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

ll solve(ll x, ll y, ll m, ll n){
    ll i; // store the last col
    if(y==1) for(i=1;i<=m;i++) cout << x << " " << i << endl;
    else if (y==m) for(i=m;i>=1;i--) cout << x << " " << i << endl;
    else {
        for(i=y;i<=m;i++) cout << x << " " << i << endl;
        for(i=y-1;i>=1;i--) cout << x << " " << i << endl;
    }
    return i==0?1:i;
}

int main()  
{ 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    #endif
    FAST_INP;
    ll n,m,x,y;
    cin >> n >> m >> x >> y;
    // UPD after contest: 
    // I think it can be just traverse from 1<=n and 1<m, skip if i=x and j=y
    // It should be more simple
    if(x==1) {
        for(int i=1;i<=n;i++){
            y = solve(i,y,m,n);
        }
    }else if(x==n){
        for(int i=n;i>=1;i--){
            y = solve(i,y,m,n);
        }
    }else{
        y = solve(x,y,m,n);
        for(int i=1;i<=x-1;i++){
            y = solve(i,y,m,n);
        }
        for(int i=x+1;i<=n;i++){
            y = solve(i,y,m,n);
        }
    }
    return 0;
} 
