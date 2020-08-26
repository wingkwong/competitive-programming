/*
Codeforces Round #636 (Div. 3) - A. Candies
https://codeforces.com/contest/1343/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve(){
	int n;
	cin >> n;
	for(int k=2;k<=29;k++){
		// (2^k-1)x=n
		// x=n/(2^k-1)
		int v=(1<<k)-1;
		if(n%v==0){
			cout << n/v << endl;
			return;
		}
	}
	return;
}

int main()  
{ 
    FAST_INP;
    int t;
    cin >> t;
    while(t--){
    	solve();
	}
    return 0;
} 
