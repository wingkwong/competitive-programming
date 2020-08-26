/*
Chef and Card Game - Problem Code: CRDGAME
https://www.codechef.com/viewsolution/34951273
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int ds(int val){
    // calculate digit sum
	int sum=0;
	while(val){
		sum+=val%10;
		val/=10;
	}
	return sum;
}

int main()  
{ 
    FAST_INP;
    int t,n,a,b,c,m;
    cin >> t;
    while(t--){
    	cin >> n;
    	c=0,m=0;
    	for(int i=0;i<n;i++){
    		cin >> a >> b;
            // get the digit sum
    		int aa = ds(a), bb = ds(b);
    		if(aa>bb){
                // Chef who draws the card with higher power wins this round and gets a point
    			c++;
			}else if(aa==bb) {
                // If the powers of both players' cards are equal then they get 1 point each.
				c++;
				m++;
			}else{
                // Morty who draws the card with higher power wins this round and gets a point
				m++;
			}
		}
		
		if(c>m) cout << 0 << " " << c;
		else if(c<m) cout << 1 << " " << m;
		else cout << 2 << " " << c;
		cout << "\n";
		
	}
    return 0;
} 