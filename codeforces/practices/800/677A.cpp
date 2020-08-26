/*
Codeforces Round #355 (Div. 2) - A. Vanya and Fence
https://codeforces.com/problemset/problem/677/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,h,a;
    cin >> n >> h;
    int sum=0;
    for(int i=0;i<n;i++){
    	cin >> a;
    	if(a>h) sum+=2;
		else sum+=1; 
	}
	cout << sum;
    return 0;
} 
