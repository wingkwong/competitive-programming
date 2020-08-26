/*
Codeforces Round #653 (Div. 3) - B. Multiply by 2, divide by 6
https://codeforces.com/contest/1374/problem/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int solve(int n){
	int c2=0,c3=0;
	while(n%3==0){
		c3++;
		n/=3;
	}
	while(n%2==0){
		c2++;
		n/=2;
	}
	// -1 cases
	if(n>1||c2>c3) return -1;
	// c3-c2: how many times to multiply by 2
	// c3: how many times to divide by 6
	return c3-c2+c3;
}

int main()  
{ 
    FAST_INP;
    int n,t;
    cin >> t;
    while(t--){
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
} 
