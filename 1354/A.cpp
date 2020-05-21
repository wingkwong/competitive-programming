/*
Educational Codeforces Round 87 (Rated for Div. 2) - A. Alarm Clock
https://codeforces.com/contest/1354/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    long long t,a,b,c,d;
    cin >> t;
    while(t--){
        cin >>a>>b>>c>>d;
		// Polycarp wakes up rested enough after the first alarm
		// take b directly
        if(b>=a){
        	cout << b << "\n";
        	continue;
		}
		
		// Polycarp keeps resetting his alarm infinitely being unable to rest for even a single minute
		if(c<=d){
        	cout << -1 << "\n";
        	continue;
		}
		
		long long m = a-b;
		long long r = c-d;
		// calculate how many times Polycarp needs to reset the alarm
		long long x = m/r;
		// add 1 if there is a remainer
		if(m%r){
			x++;
		}
		cout << b+(x*c) << "\n";
    }
    return 0;
} 

