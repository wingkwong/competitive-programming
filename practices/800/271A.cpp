/*
Codeforces Round #166 (Div. 2) - A. Beautiful Year
https://codeforces.com/problemset/problem/271/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int y;
    cin >> y;
    while(1){
    	y++;
    	int f=1;
    	string yy=to_string(y);
    	for(int i=0;i<4;i++){
    		for(int j=0;j<4;j++){
    			if(i==j) continue;
    			if(yy[i]==yy[j]){
    				f=0;
				}
			}
		}
		if(f) break;
	}
	cout << y << "\n";
    return 0;
} 
