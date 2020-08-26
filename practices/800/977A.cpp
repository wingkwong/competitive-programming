/*
Codeforces Round #479 (Div. 3) - A. Wrong Subtraction
https://codeforces.com/problemset/problem/977/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,k;
    cin >> n >> k;
    while(k--){
    	if(n%10==0){
    		n/=10;
		} else {
			n-=1;
		}
	}
	cout << n << "\n";
    return 0;
} 
