/*
Codeforces Round #655 (Div. 2) - A. Omkar and Completion
https://codeforces.com/contest/1372/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n;
    cin >> t;
    while(t--){
    	cin >> n;
    	for(int i=0;i<n;i++){
			// ax+ay!=a 
			// X,Y,Z can be equal
			// hence, print 1 for n times 
    		cout << 1 << " ";
		}
		cout << "\n";
	}
    return 0;
} 
