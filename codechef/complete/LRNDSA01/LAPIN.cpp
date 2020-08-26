/*
DSA Learning Series - Contest 1 - Lapindromes 
https://www.codechef.com/LRNDSA01/problems/LAPIN
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    int t; cin >> t;
    string s;
    while(t--){
    	cin >> s;
    	int n = s.size();
    	string s1 = s.substr(0,n/2);
    	string s2 = s.substr((n/2)+(n&1?1:0),n-(n/2)+1);
    	sort(s1.begin(),s1.end());
    	sort(s2.begin(),s2.end());
    	cout << (s1==s2?"YES":"NO") << endl;
	}
    return 0;
} 
