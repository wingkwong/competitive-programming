/*
Codeforces Beta Round #84 (Div. 2 Only) - A. Nearly Lucky Number
https://codeforces.com/problemset/problem/110/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    long long n,cnt=0;
    cin >> n;
    while(n){
    	if(n%10==4||n%10==7) cnt++;
    	n/=10;
	}
	cout << (cnt==4||cnt==7?"YES":"NO") << "\n";
    return 0;
} 
