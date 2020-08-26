/*
AIsing Programming Contest 2020 - B - An Odd Problem
https://atcoder.jp/contests/aising2020/tasks/aising2020_b
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int n;
    cin >> n;
    int ans=0;
    for(int i=1;i<=n;i++) {
    	int a;
    	cin >> a;
//    	check if the assigned number, i, is odd, and
//		check if the written integer is odd
    	if((i&1)&&(a&1)) ans++;
	}
	cout << ans;
    return 0;
} 
