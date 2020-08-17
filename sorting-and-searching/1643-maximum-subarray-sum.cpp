/*
Maximum Subarray Sum
https://cses.fi/problemset/task/1643

Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.

Input

The first input line has an integer n: the size of the array.

The second line has n integers x1,x2,…,xn: the array values.

Output

Print one integer: the maximum subarray sum.

Constraints
1≤n≤2⋅105
−109≤xi≤109
Example

Input:
8
-1 3 -2 5 3 -5 2 2

Output:
9
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // #endif
    FAST_INP;
    ll n;
    cin >> n;
    vector<ll> x(n);
    for(auto &k:x) cin >> k;
    ll c,g;
    c=g=x[0];
    // kadane's algorithm
    for(int i=1;i<=n-1;i++){
        c=max(x[i],c+x[i]);
        g=max(g,c);
    }
    cout << g << endl;
    return 0;
} 