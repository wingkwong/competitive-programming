/*
Codeforces Round #658 (Div. 2) - C2 - Prefix Flip (Hard Version)
https://codeforces.com/contest/1382/problem/D
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,t;
        string s1,s2;
    cin >> t;
    while(t--){
    	// make s1 to all zeros
    	// make all zeros to s2
        cin >> n >> s1 >> s2;
        s1+='0', s2+='0';
        vector<int> v1, v2;
        for(int i=1;i<=n;i++){
        	if(s1[i]!=s1[i-1]) v1.emplace_back(i);
        	if(s2[i]!=s2[i-1]) v2.emplace_back(i);
		}
		v1.insert(v1.end(), v2.rbegin(), v2.rend());
		cout << v1.size() << " ";
		for(int k:v1) cout << k << " ";
		cout << endl;
    }
    return 0;
} 
