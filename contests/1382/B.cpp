/*
Codeforces Round #658 (Div. 2) - Sequential Nim
https://codeforces.com/contest/1382/problem/B
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
        vector<int> p(n);
        for(int i=0;i<n;i++) cin >> p[i];
        int k=0;
        // whoever gets the first pile with more than one stone wins
        while(k<n&&p[k]==1) k++;
        // if all piles have 1 stone, the first player wins when k is odd
        cout << ((k==n)^(k%2)?"Second":"First") << "\n";
    }
    return 0;
} 
 
