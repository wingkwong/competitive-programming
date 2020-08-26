/*
Codeforces Round #660 (Div. 2) - A. Captain Flint and Crew Recruitment
https://codeforces.com/contest/1388/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

void solve(){
	int n; cin >> n;
	if (n<=30) {
		// the first 3 nearly prime numbers are 6,10 and 14
		// so n<=6+10+14 is NO
	    printf("NO\n");
	} else {
	    printf("YES\n");
	    int k=n-30; 
	    if (k==6||k==10||k==14) {
	    	// since we need 4 different numbers 
	    	// if k is either 6,10 or 14, take n-31 instead
	        k=n-31; 
	        printf("6 10 15 %d\n", k);
	    } else {
	    	// else just print 6 10 14 n-k
	        printf("6 10 14 %d\n", k);
	    }
	}
}

int main()  
{ 
    FAST_INP;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
} 
