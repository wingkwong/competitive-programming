/*
AISing Programming Contest 2019 - A - Bulletin Board
https://atcoder.jp/contests/aising2019/tasks/aising2019_a
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int h,w,n;
    cin >> n >> h >> w;
    cout << (n-h+1)*(n-w+1);
    return 0;
} 
