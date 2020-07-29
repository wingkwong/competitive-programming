/*
Missing a Point - Problem Code: PTMSSNG
https://www.codechef.com/JULY20B/problems/PTMSSNG
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n,x,y;
    cin >> t;
    while(t--){
        int ansx=0, ansy=0;
        cin >> n;
    	for(int i=0;i<4*n-1;i++){
            cin >> x >> y;
            // both x-axis and y-axis missing one point
            // use XOR to find out 
            ansx^=x;
            ansy^=y;
        }
        cout << ansx << " " << ansy << "\n";
	}
    return 0;
} 