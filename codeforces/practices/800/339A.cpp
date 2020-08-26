/*
Codeforces Round #197 (Div. 2) - A. Helpful Maths
https://codeforces.com/problemset/problem/339/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    string s;
    cin >> s;
    vector<int> v;
    for(int i=0;i<s.size();i++){
    	if(isdigit(s[i])) v.push_back(s[i]+'0');
	}
	sort(v.begin(),v.end());
	string ans="";
	for(int i=0;i<v.size();i++){
		ans+=v[i]-'0';
		if(i!=v.size()-1) ans+="+";
	}
	cout << ans << "\n";
    return 0;
} 

