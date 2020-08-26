/*
A. Orac and Factors
https://codeforces.com/contest/1350/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int t,n,k; 
    cin >> t;
    while(t--){
        cin >> n >> k;
        // n is even: n+2k
        // n is odd : n+2(k-1)+f(n)
        if(n%2==0){
            cout << n+2*k << "\n";
            continue;
        }

        int fn=0;
        for(int i=n;i>=2;i--){
            if(n%i==0){
                fn=i;
            }
        }

        cout << n+2*(k-1)+fn << "\n";
    }
    return 0;
} 