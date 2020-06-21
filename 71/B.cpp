/*
Codeforces Beta Round #65 (Div. 2)
https://codeforces.com/problemset/problem/71/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,k,t;
    cin>>n>>k>>t;
    // convert the formula to find the max a
    int x=n*k*t/100;
    for(int i=0;i<n;i++){
        // full saturation of the square  
    	if(x>k) cout << k << " ";
        // process not complete. print 0
    	else if(x<0) cout << 0 << " ";
        // x is smaller than k, print x instead
		else cout << x << " ";
        // update x
		x-=k;	
	}
    return 0;
} 

