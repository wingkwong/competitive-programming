/*
Increasing Array
https://cses.fi/problemset/task/1094

You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.

On each turn, you may increase the value of any element by one. What is the minimum number of turns required?

Input

The first input line contains an integer n: the size of the array.

Then, the second line contains n integers x1,x2,…,xn: the contents of the array.

Output

Print the minimum number of turns.

Constraints
1≤n≤2⋅105
1≤xi≤109
Example

Input:
5
3 2 5 1 7

Output:
5
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    long long n,ans=0;
    cin >> n;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin >> x[i];
    for(int i=1;i<n;i++){
    	// if x[i] is smaller than the previous one 
    	if(x[i]<x[i-1]) {
    		// then x[i] needs x[i-1]-x[i] to be at least as large as the previous element
    		ans+=x[i-1]-x[i];
    		// update x[i]
    		x[i]=x[i-1];
		}
	}
	cout << ans << "\n";
    return 0;
} 
