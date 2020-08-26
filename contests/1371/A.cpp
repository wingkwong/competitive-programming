/*
Codeforces Round #654 (Div. 2) - A. Magical Sticks
https://codeforces.com/contest/1371/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,t;
    cin >> t;
    while(t--){
        cin >> n;
        if(n%2==0) cout << n/2 << endl;
        else cout << (n/2)+1 << endl;
        // or cout << (n+1)/2 << endl;
    }
    return 0;
} 
