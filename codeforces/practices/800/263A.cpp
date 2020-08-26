/*
Codeforces Round #161 (Div. 2) - A. Beautiful Matrix
https://codeforces.com/problemset/problem/263/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int d,ii,jj,f=0;
    for(int i=1;i<=5;i++){
    	for(int j=1;j<=5;j++){
    		cin >> d;
    		if(d==1){
    			ii=i;
    			jj=j;
			}
		}
	}
    
	cout << (abs(ii-3)+abs(jj-3)) << "\n";
    return 0;
} 

