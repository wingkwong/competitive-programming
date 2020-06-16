/*
CodeChef June Challenge 2020 Division 2 - Chef and Icecream
https://www.codechef.com/JUNE20B/problems/CHFICRM
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

bool solve(int n){
	vector<int> a(n);
	// store how many coins the Chef has
	int c5=0,c10=0,c15=0;
	// read input
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++){
		if(a[i]==5) {
			// no change is required
			c5++;
		} else if(a[i]==10) {
			// need to give back Rs. 5 coin
			// if no Rs .5, we can end it and the ans is NO 
			if(c5==0) {
				return false;
			}
			// update the coins
			c5--;
			c10++;
		}
		else if(a[i]==15) {
			// I got WA on my first try as I thought "exact change" means giving back Rs. 10 only in this case...
			// --------------------------------------------------------------------------------------------------------
			// The Chef needs to give back Rs. 10 coin which can further break into 2 cases
			// he either gives back 2 x Rs .5 or 1 x Rs .10
			if(c10==0&&c5<2){
				return false;
			}
			// if Chef doesn't have Rs .10 but 2 x Rs .5, deduct 2 x Rs .5
			if(c10==0) c5-=2;
			// else deduct 1 x Rs .10
			else c10--;
			// receive Rs .15
			c15++; 
		}
	}
	return true;
}

int main()  
{ 
    FAST_INP;
    int t,n;
    cin >> t;
    while(t--){
    	cin >> n;
    	if(solve(n)) cout << "YES\n";
		else cout << "NO\n";
	}
    return 0;
} 
