/*
B - Easy Linear Programming
https://atcoder.jp/contests/abc167/tasks/abc167_b
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    long long a,b,c,k;
    cin >> a >> b >> c >> k;
    // get all As first, then B, then C
    // if k is less than a, that means we just need to take k cards with 1s
    if(k<a){
        cout << k << "\n";
        return 0;
    }
    // if k is less than / equal to a+b
    // all cards with 1s will be taken, i.e a
    if(k<=a+b) {
        cout << a << "\n";
        return 0;
    }
    // if k > a+b
    // take all 1s ---> value: a
    // take all 0s ---> value: 0
    // take k-(a+b) ---> value: k-(a+b)*-1
    // ans = a + 0 + k-(a+b)*-1
    //     = a + (k-a-b)*-1
    //     = a + -k+a+b
    //     = 2*a - k + b
    cout << 2*a-k+b << "\n";
    return 0;
} 