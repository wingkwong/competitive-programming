/*
CodeChef June Challenge 2020 Division 2 - Chef and Price Control
https://www.codechef.com/JUNE20B/problems/PRICECON
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n,p,k;
    cin >> t;
    while(t--){
    	cin >> n >> k;
    	int ans1=0,ans2=0;
    	for(int i=0;i<n;i++){
    		cin >> p;
			// for each item i such that Pi>K, 
			// its price should be reduced from Pi to K.
    		if(p>k) ans2+=k;
    		else ans2+=p;
			// initial revenue
    		ans1+=p;
		}
		// lost revenue
		cout << ans1-ans2 << "\n";
	}
    return 0;
} 
