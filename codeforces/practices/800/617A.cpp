/*
Codeforces Round #340 (Div. 2) - A. Elephant
https://codeforces.com/problemset/problem/617/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int x,ans=0;
    cin >> x;
    while(x){
    	if(x-5>=0) {
	    	x-=5; ans++;
		} else if(x-4>=0) {
	    	x-=4; ans++;
		} else if(x-3>=0) {
	    	x-=3; ans++;
		} else if(x-2>=0) {
	    	x-=2; ans++;
		} else if(x-1>=0) {
	    	x-=1; ans++;
		}
	}
	// faster way: 
	// ans = (x+4)/5;
	cout << ans << "\n";
    return 0;
} 
