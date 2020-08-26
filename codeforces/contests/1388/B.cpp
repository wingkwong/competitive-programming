/*
Codeforces Round #660 (Div. 2) - B. Captain Flint and a Long Voyage
https://codeforces.com/contest/1388/problem/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

void solve(){
	int n; cin >> n;
	// max r - when at least 4*x-3 digits are removed
	// 4*x-3<=n
	// x<=(n+3)/4
	int x=(n+3)/4;
	for(int i=0;i<n-x;i++) printf("9");
	for(int i=0;i<x;i++) printf("8");
	printf("\n");
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
//
//n=5
//99999
//10011001100110011001
//100110011001100-----
//99988
//10011001100110001000
//100110011001100-----
