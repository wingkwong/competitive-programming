/*
Codeforces Round #656 (Div. 3) - C. Make It Good
https://codeforces.com/contest/1385/problem/C
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
        vector<int> v(n);
        for(auto &x:v) cin >>x;
        // a1<=a2<=...<=ax>=...>=ak-1>=ak-2<=ak2
        int k=n-1;
        while(k>0&&v[k-1]>=v[k]) k--;
        while(k>0&&v[k-1]<=v[k]) k--;
        cout << k << "\n";
    }
    return 0;
} 

