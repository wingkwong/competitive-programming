/*
Codeforces Round #632 (Div. 2) - A. Little Artem
https://codeforces.com/contest/1333/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,m,n;
    cin >> t;
    while(t--){
        cin >> m >> n;
        for(int i=0;i<m;i++){
        	for(int j=0;j<n;j++){
        		// paint the top left corner to white
        		if(i==0&j==0) cout << 'W';
        		// paint others to black
        		else cout << 'B';
        		// then it can have B=W+1 for any size
			}
			cout << "\n";
		}
    }
    return 0;
} 
