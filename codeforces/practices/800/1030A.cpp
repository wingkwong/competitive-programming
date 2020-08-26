/*
Technocup 2019 - Elimination Round 1 - A. In Search of an Easy Problem
https://codeforces.com/problemset/problem/1030/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,k;
    cin >> n;
    while(n--){
    	cin >> k;
		if(k) {
			cout << "HARD";
			return 0;
		} 
	}
	cout << "EASY";
    return 0;
} 
