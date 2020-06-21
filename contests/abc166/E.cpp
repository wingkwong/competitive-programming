/*
E - This Message Will Self-Destruct in 5s
https://atcoder.jp/contests/abc166/tasks/abc166_e
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int n; 
    cin >> n;
    int a[n+1];
    long long ans=0;
    unordered_map<int,int> m;
    // find a pair (i,j) where j > i and j-i is equal to the sum of their heights
    // j-i = A[j]+A[i]
    // j-A[j] = i+A[i]
    for(int i=1;i<=n;i++){
        cin >> a[i];
        ans+=m[i-a[i]];
        m[i+a[i]]++;
    }
    cout << ans << "\n";
    return 0;
} 