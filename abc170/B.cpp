/*
AtCoder Beginner Contest 170 - B - Crane and Turtle
https://atcoder.jp/contests/abc170/tasks/abc170_b
*/
#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int x,y;
    cin >> x >> y;
    // based on what we have, we can write the below equations 
    // let crane be a & turtle be b
    // x=a+b -- (1)
    // y=2a+4b -- (2)
    // reorder (1)
    // b=x-a -- (3)
    // put (3) into (2), we got a=(4x-y)/2
    int a = (4*x-y)/2;
    int aa = (4*x-y)%2; // we need to make sure there is no remainder 
    int b = x - a;
    if( a>=0 && aa == 0 && b>=0 ) cout << "Yes\n";
    else cout << "No\n";
    return 0;
} 