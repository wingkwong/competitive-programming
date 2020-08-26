/*
Sum of Two Values
https://cses.fi/problemset/task/1640

You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.

Input

The first input line has two integers n and x: the array size and the target sum.

The second line has n integers a1,a2,…,an: the array values.

Output

Print two integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.

Constraints
1≤n≤2⋅105
1≤x,ai≤109
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
    ll n,x,a;
    cin >> n >> x;
    map<ll,ll> m; // use unordered_map would cause TLE on Test 11
    for(int i=0;i<n;i++) {
        cin >> a;
        // find the complement
        if(m.find(x-a)!=m.end()){
            cout << m[x-a]+1 << " " << i+1 << endl;
            return 0;
        }
        m[a]=i;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
} 