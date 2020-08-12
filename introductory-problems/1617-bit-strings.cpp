/*
Bit Strings
https://cses.fi/problemset/task/1617

Your task is to calculate the number of bit strings of length n.

For example, if n=3, the correct answer is 8, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.

Input

The only input line has an integer n.

Output

Print the result modulo 109+7.

Constraints
1=n=106
Example

Input:
3

Output:
8
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int n, ans=1,mod=1e9+7;
    cin >> n;
    // cout << (1<<n)%mod;
    for(int i=0;i<n;i++) ans=(ans*2)%mod;
	cout << ans;
    return 0;
} 
