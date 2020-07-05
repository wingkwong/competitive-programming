/*
Codeforces Round #624 (Div. 3) - A. Add Odd or Subtract Even
https://codeforces.com/problemset/problem/1311/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,a,b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        // do nothing
        if(a==b) cout << 0 << "\n";
        // choose any positive even integer y (y>0) and replace a with a-y.
        else if(a>b&&(a-b)%2==0) cout << 1 << "\n";
        // choose any positive odd integer x (x>0) and replace a with a+y.
        else if(a<b&&(b-a)%2==1) cout << 1 << "\n";
        // add it to the closest one and add/substract 1 
        else cout << 2 << "\n";
    }
    return 0;
} 
