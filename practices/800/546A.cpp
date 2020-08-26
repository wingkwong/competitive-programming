/*
Codeforces Round #304 (Div. 2) - A. Soldier and Bananas
https://codeforces.com/problemset/problem/546/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int k,n,w;
    cin >> k >> n >> w;
    int t=0;
    for(int i=1;i<=w;i++) t+=i*k;
	cout << (n>t?0:t-n) << "\n";
    return 0;
} 

