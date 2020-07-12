/*
AIsing Programming Contest 2020 - C - XYZ Triplets
https://atcoder.jp/contests/aising2020/tasks/aising2020_c
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n;
    cin >> n;
    unordered_map<int,int> ans(n);
    // pre-build the ans map
    // note that N<= 10^4
	for(int x=1;x<=105;x++){
		for(int y=1;y<=105;y++){
			for(int z=1;z<=105;z++){
				int k = (x*x)+(y*y)+(z*z)+(x*y)+(y*z)+(z*x);
				if( k < 10005 ) {
					ans[k]++;
				} 
			}
		}
	}
    for(int i=1;i<=n;i++) cout << ans[i] << "\n";
    return 0;
} 
