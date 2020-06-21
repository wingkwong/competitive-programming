/*
Codeforces Beta Round #4 (Div. 2 Only) - C. Registration system
https://codeforces.com/problemset/problem/4/C
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n;
    string s;
    map<string,int> m;
    cin >> n;
    while(n--){
    	cin >> s;
        // if it exists before, append the number
    	if(m[s]) cout << s << m[s] << "\n";
		else cout << "OK\n";
        // store the occurrence of input  
		m[s]++;
	}
    return 0;
} 
