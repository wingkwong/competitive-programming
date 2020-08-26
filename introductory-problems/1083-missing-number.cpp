/*
Missing Number
https://cses.fi/problemset/task/1083

You are given all numbers between 1,2,…,n except one. Your task is to find the missing number.

Input

The first input line contains an integer n.

The second line contains n−1 numbers. Each number is distinct and between 1 and n (inclusive).

Output

Print the missing number.

Constraints
2≤n≤2⋅105
Example

Input:
5
2 3 1 5

Output:
4
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    long long n,d,sum=0; 
    cin >> n;
	for(int i=0;i<n-1;i++) {
		cin >> d;
		sum+=d;
	}
	// n*(n+1)/2 - find the sum of 1..n
	// ans = the sum of 1..n - the sum of input
	cout << n*(n+1)/2 - sum  << "\n";
    return 0;
} 
