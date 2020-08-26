#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n;
    cin >> t;
    while(t--){
       cin >> n;
       for(int i=0;i<n;i++) cin >> a[i];

       int sum=0,ans=0;
       for(int v:a){
            sum+=v;
            if(sum==v){
                ans++;
                
            }
       }
    }
    return 0;
} 