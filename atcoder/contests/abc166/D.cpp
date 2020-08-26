/*
D - I hate Factorization
https://atcoder.jp/contests/abc166/tasks/abc166_d
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int x; 
    cin >> x;
    for(int i=-118;i<=119;i++){
        for(int j=-119;j<=118;j++){
            if(pow(i,5)-pow(j,5)==x) {
                cout << i << " " << j << "\n";
                return 0;
            }
        }
    }
    return 0;
} 