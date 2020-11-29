/*
Educational Codeforces Round 85 (Rated for Div. 2) - A. Level Statistics
https://codeforces.com/contest/1334/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n,x,y;
    cin >> t;
    while(t--){
        cin >> n;
        int ans=1,px=0,py=0;
        for(int i=0;i<n;i++){
        	cin >> x >> y;
        	if(
				x<px || // the current number of plays cannot be smaller than the previous number of plays
				y<py || // the current number of clears cannot be smaller than the previous number of clears 
				y-py > x-px  // number of clears cannot be smaller than the number of plays for one jump
			) {
				ans=0;
			}
			
			px=x; py=y;
		}
		if(ans) cout << "YES\n";
		else cout << "NO\n";
    }
    return 0;
} 
