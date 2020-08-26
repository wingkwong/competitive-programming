/*
Codeforces Beta Round #97 (Div. 2) - A. Presents
https://codeforces.com/problemset/problem/136/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n;
    cin >> n;
    vector<int> p(n+1),pp(n+1);
    for(int i=1;i<=n;i++) {
    	cin >> p[i];
    	pp[p[i]]=i;
	}
    for(int i=1;i<=n;i++) {
    	cout << pp[i] << " ";
	}
    return 0;
} 
