/*
VK Cup 2012 Qualification Round 1 - A. Next Round
https://codeforces.com/problemset/problem/158/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,k,ans=0;
    cin >> n >> k;
    vector<int> v(n);
    k--;
    for(int i=0;i<n;i++) {
    	cin >> v[i];
    	if(v[i]){
    		if(i<=k||(i>k&&v[i]==v[k])) ans++;
		}
	}
	cout << ans << "\n";
    return 0;
} 
 
