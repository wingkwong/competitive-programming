/*
Codeforces Round #654 (Div. 2) - C. A Cookie for You
https://codeforces.com/contest/1371/problem/C
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    long long t,a,b,n,m;
    cin >> t;
    while(t--){
        // just math
        cin >> a >> b >> n >> m;
        if(min(a,b)<m) cout << "No" << endl;
	    else if(a+b<n+m) cout << "No" << endl;
	    else cout << "Yes" << endl;
    }
    return 0;
} 
