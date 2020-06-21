/*
Codeforces Beta Round #55 (Div. 2) - A. Word
https://codeforces.com/problemset/problem/59/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    string s,ans1="",ans2="";
    int l=0,u=0;
    cin >> s;
    for(int i=0;i<s.size();i++){
    	if(islower(s[i])) l++;
    	else u++;
    	
    	ans1+=tolower(s[i]);
    	ans2+=toupper(s[i]);
    	
	}
	cout << (l>=u?ans1:ans2) << "\n";
    return 0;
} 
