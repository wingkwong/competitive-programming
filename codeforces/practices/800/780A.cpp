/*
Технокубок 2017 - Финал (только для онсайт-финалистов) - A. Andryusha and Socks
https://codeforces.com/contest/780/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,x;
    cin >> n;
    unordered_map<int,int> m;
    int ans=0,cnt=0;
    for(int i=0;i<n*2;i++){
        cin >> x;
        if(m[x]) cnt--;
        else {
            cnt++;
            m[x]=1;
        }
        ans=max(ans,cnt);
    }
    cout << ans << "\n";
    return 0;
} 
