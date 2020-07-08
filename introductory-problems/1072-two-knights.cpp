/*
Two Knights
https://cses.fi/problemset/task/1072

Your task is to count for k=1,2,…,n the number of ways two knights can be placed on a k×k chessboard so that they do not attack each other.

Input

The only input line contains an integer n.

Output

Print n integers: the results.

Constraints
1≤n≤10000
Example

Input:
8

Output:
0
6
28
96
252
550
1056
1848
*/
#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    long long n;
    cin >> n;
    for(int k=1;k<=n;k++){
        // the first knight can be placed in k2 ways
        long long k2 = k*k;
        // the second knight can be placed in k2-1 ways
        // the number of ways to place two knights is k2*(k2-1)
        // two knights cannot be placed in the same cells, de-duplicate by diviving by 2, i.e. k2*(k2-1)/2
        // a knight can attack in a form of 2x3 and 3x2 chessboard, 
        // for 2x3: (n-2+1)(n-3+1) = (n-1)(n-2)
        // for 3x2: (n-3+1)(n-2+1) = (n-2)(n-1)
        // hence 2x3 + 3x2: (n-1)(n-2) + (n-2)(n-1) -> 2(n-1)(n-2)
        // the two knights can be swapped, so multiply by 2
        // combine it together, that would be 4(k-1)(k-2)
        cout << (k2*(k2-1)/2 - 4*(k-1)*(k-2)) << "\n";
    }
    return 0;
} 