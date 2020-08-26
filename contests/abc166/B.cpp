/*
B - Trick or Treat
https://atcoder.jp/contests/abc166/tasks/abc166_b
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int n,k,d,a; 
    cin >> n >> k;
    unordered_map<int,int> m;
    while(k--){
        cin >> d;
        for(int i=0;i<d;i++){
            cin >> a;
            // no need to care about what snack does a snuke have 
            m[a]++;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        // if snuke i has no stack, increase ans by 1
        if(!m[i]) ans++;
    }
    cout << ans << "\n";
    return 0;
} 