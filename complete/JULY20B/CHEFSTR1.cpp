/*
Chef and Strings - Problem Code: CHEFSTR1
https://www.codechef.com/JULY20B/problems/CHEFSTR1/
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    long long t,n;
    cin >> t;
    while(t--){
    	cin >> n;
    	vector<int> s(n);
    	for(int i=0;i<n;i++) cin >> s[i];
    	long long ans=0;
    	for(int i=1;i<n;i++) {
            // sum up the number of strings to skip
    		ans+=abs(s[i]-s[i-1])-1;
		}
		cout << ans << "\n";
	}
    return 0;
} 