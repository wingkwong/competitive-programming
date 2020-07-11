/*
Trailing Zeros
https://cses.fi/problemset/task/1618/

Your task is to calculate the number of trailing zeros in the factorial n!.

For example, 20!=2432902008176640000 and it has 4 trailing zeros.

Input

The only input line has an integer n.

Output

Print the number of trailing zeros in n!.

Constraints
1=n=109
Example

Input:
20

Output:
4
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int n, cnt=0;
    cin >> n;
    // just count of 5s in prime factors of n!
    for(int i=5;i<=n;i*=5) cnt+=n/i;
    cout << cnt;
    return 0;
} 
