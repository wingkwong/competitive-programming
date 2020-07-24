/*
Testing Beta Round (Unrated) - A. 123-sequence
https://codeforces.com/contest/1390/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int,int> m;
    for(auto k:a){
    	cin >> k;
    	m[k]++;
	}
	
	cout << min({
		m[1]+m[2],
		m[2]+m[3],
		m[3]+m[1]
	}) << endl;
    return 0;
} 
