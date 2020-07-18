/*
Codeforces Round #656 (Div. 3) - B. Restore the Permutation by Merger
https://codeforces.com/contest/1385/problem/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> s;
        int p;
        for(int i=0;i<2*n;i++){
        	cin >> p;
        	// use find to see if it exists
        	if(find(s.begin(),s.end(),p) == s.end()) {
        		s.push_back(p);
			}
		}
		for(auto x:s) cout << x << " ";
		cout << "\n";
    }
    return 0;
} 

int sol2()  
{ 
    FAST_INP;
    int n,t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> s;
        unordered_map<int,int> m;
        int p;
        for(int i=0;i<2*n;i++){
        	cin >> p;
        	// use unordered_map to see if it exists
        	if(!m[p]) {
        		s.push_back(p);
				m[p]=1;
			}
		}
		for(auto x:s) cout << x << " ";
		cout << "\n";
    }
    return 0;
} 
