/*
DSA Learning Series - Contest 1 - Reverse The Number
https://www.codechef.com/LRNDSA01/problems/FLOW007
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    int t,n; cin >> t;
    while(t--){
    	cin >> n;
    	string s = to_string(n);
    	reverse(s.begin(),s.end());
    	int i=0;
    	while(s[i]=='0') i++;
    	int sz = s.size();
    	cout << s.substr(i,sz-i+1) << endl;
	}
    return 0;
} 
