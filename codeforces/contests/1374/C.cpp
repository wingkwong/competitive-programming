/*
Codeforces Round #653 (Div. 3) - C. Move Brackets
https://codeforces.com/contest/1374/problem/C
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int solve(string s){
	int l=0,ans=0;
	for(char c:s){
		if(c=='('){
			l++;
		} else{
			l--;
			if(l<0) 
				// if l s less than 0, 
				// it means this bracket needs to be moved
				l=0;
				ans++;
			}
		}
	}
	return ans;
}

int main()  
{ 
    FAST_INP;
    int n,t;
    string s;
    cin >> t;
    while(t--){
        cin >> n >> s;
        cout << solve(s) << "\n";
    }
    return 0;
} 
