/*
Educational Codeforces Round 79 (Rated for Div. 2) - A. New Year Garland
https://codeforces.com/problemset/problem/1279/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t;
    cin >> t;
    while(t--){
    	vector<int> v(3);
    	for(auto &x:v) cin >> x;
    	sort(v.begin(),v.end());
    	// R R R R R R
    	//  B B B B
    	// 			G G
		if(v[2]>(v[1]+v[0]+1)) cout << "No\n";
    	else cout << "Yes\n";
	}
    return 0;
} 

