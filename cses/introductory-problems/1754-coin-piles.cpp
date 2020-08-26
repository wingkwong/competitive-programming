/*
Coin Piles
https://cses.fi/problemset/task/1754

You have two coin piles containing a and b coins. On each move, you can either remove one coin from the left pile and two coins from the right pile, or two coins from the left pile and one coin from the right pile.

Your task is to efficiently find out if you can empty both the piles.

Input

The first input line has an integer t: the number of tests.

After this, there are t lines, each of which has two integers a and b: the numbers of coins in the piles.

Output

For each test, print "YES" if you can empty the piles and "NO" otherwise.

Constraints
1=t=105
0=a,b=109
Example

Input:
3
2 1
2 2
3 3

Output:
YES
NO
YES
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int t,a,b;
    cin >> t;
  	while(t--){
  		cin >> a >> b;
  		if(a<b) swap(a,b);
  		cout << ((a+b)%3==0&&a<=2*b?"YES\n":"NO\n");
	}
    return 0;
} 

// a=2x+y
// b=x+2y
// x=(2a-b)/3
// y=(2b-a)/3
