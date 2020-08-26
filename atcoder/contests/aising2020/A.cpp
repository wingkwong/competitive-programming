/*
AIsing Programming Contest 2020 - A - Number of Multiples
https://atcoder.jp/contests/aising2020/tasks/aising2020_a
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int l,r,d;
    cin >> l >> r>> d;
    int ans=0;
    // check if i can be divided by d without a remainder 
    for(int i=l;i<=r;i++){
    	if(i%d==0) ans++;
	}
	cout << ans;
    return 0;
} 
