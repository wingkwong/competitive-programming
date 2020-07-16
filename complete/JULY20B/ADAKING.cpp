/*
Ada King - Problem Code: ADAKING
https://www.codechef.com/JULY20B/problems/ADAKING
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve(int k){
    // a bit hacky
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			k--;
            // place the king at (0,0) 
			if(i==0&&j==0){
				cout << 'O';
				continue;
			}
			// place . k times 
			if(k>=0) cout << '.';
            // place X on the rest of the cells
			else cout << 'X';
		}
		cout << "\n";
	}	
}

int main()  
{ 
    FAST_INP;
    int t, k;
    cin >> t;
    while(t--){
    	cin >> k;
    	solve(k);
	}
    return 0;
} 