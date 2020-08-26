/*
Codeforces Round #173 (Div. 2) - A. Bit++
https://codeforces.com/problemset/problem/282/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,ans=0;
    cin >> n;
    while(n--){
    	string s;
    	cin >> s;
    	if(count(s.begin(),s.end(),'+')) ans++;
    	else ans--;
	}
	cout << ans << "\n";
    return 0;
} 

