/*
Codeforces Round #642 (Div. 3) - A. Most Unstable Array
https://codeforces.com/contest/1353/problem/A
*/
#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n,m; 
    cin >> t;
    while(t--){
    	cin >> n >> m;
    	// to achive max value, we need to separate each value with 0
    	// m*2 would be the answer for n >=2 
    	// or else the ans would be m
    	cout << min(2,n-1)*m << "\n";
	}
    return 0;
} 
