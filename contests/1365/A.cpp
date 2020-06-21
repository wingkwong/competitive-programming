/*
Codeforces Round #648 (Div. 2) - A. Matrix Game
https://codeforces.com/contest/1365/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n,m,a;
    cin >> t;
    while(t--){
    	cin >> n >> m;
    	set<int> r,c;
        for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
        		cin >> a;
        		if(a==1) {
        			r.insert(i);
        			c.insert(j);
				}
			}
		}
		// find out how many row and col they can claim, take the minimum value
		// if it's even, Vivek must win because Ashish goes first
		int ans=min(n-r.size(), m-c.size());
		if(ans&1) cout << "Ashish\n";
		else cout << "Vivek\n";
    }
    return 0;
} 
