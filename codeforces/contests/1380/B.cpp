/*
Educational Codeforces Round 91 (Rated for Div. 2) - B. Universal Solution
https://codeforces.com/contest/1380/problem/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        int R=0,S=0,P=0;
		for(char c:s){
			if(c=='R') R++;
			else if(c=='S') S++;
			else P++;
		}        
		for(int i=0;i<s.size();i++){
			if(R>=S&&R>=P) cout << "P";
			else if (S>=R&&S>=P) cout << "R";
			else cout << "S";	
		}
		cout << "\n";
    }
    return 0;
} 
