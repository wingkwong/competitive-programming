/*
Codeforces Beta Round #26 (Codeforces format) - A. Almost Prime
https://codeforces.com/contest/26/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int N; cin >> N;
    int ans = 0;
    for(int i = 1; i <= N; i++) {
    	int x = i;
    	int cnt = 0;
    	for(int j = 2; j * j <= x; j++) {
    		if(x % j == 0) {
    			cnt++;
    			while(x % j == 0) x /= j;
    		}
    	}
    	if(x != 1) cnt++;
    	ans += cnt == 2;
    }
    cout << ans << endl;
    return 0;
} 
