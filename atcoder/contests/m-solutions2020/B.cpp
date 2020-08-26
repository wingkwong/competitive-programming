/*
M-SOLUTIONS Programming Contest 2020 - B - Magic 2
https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_b
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    int ok=0;
    while(k--){
    	// The integer on the green card is strictly greater than the integer on the red card.
		// The integer on the blue card is strictly greater than the integer on the green card.
    	// i.e. c > b > a
    	// if b is less than or equal to a, multiply b by 2
    	if(b<=a) b*=2;
    	// if c<=a, then multiply c by 2 
    	// we don't need to multiply a by 2 since it should be the smallest one
    	else c*=2;
	}
	// check if it is successful
	if(b>a&&c>b) cout << "Yes\n";
	else cout <<"No\n";
    return 0;
} 
