/*
AtCoder Beginner Contest 170 - A - Five Variables
https://atcoder.jp/contests/abc170/tasks/abc170_a
*/
#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int a,b,c,d,e; 
    // find out which one is 0 
    cin >> a >> b >> c >> d >> e;
    if(a==0) cout << 1 << endl;
    else if(b==0) cout << 2 << endl;
    else if(c==0) cout << 3 << endl;
    else if(d==0) cout << 4 << endl;
    else cout << 5 << endl; 
    return 0;
} 
