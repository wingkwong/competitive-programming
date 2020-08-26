/*
Ferris Wheel
https://cses.fi/problemset/task/1090

There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.

Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x. You know the weight of every child.

What is the minimum number of gondolas needed for the children?

Input

The first input line contains two integers n and x: the number of children and the maximum allowed weight.

The next line contains n integers p1,p2,…,pn: the weight of each child.

Output

Print one integer: the minimum number of gondolas.

Constraints
1≤n≤2⋅105
1≤x≤109
1≤pi≤x
Example

Input:
4 10
7 2 3 9

Output:
3
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
    ll n,x,cnt=0;
    cin >> n >> x;
    vector<ll> p(n);
    for(auto &k:p) cin >> k;
    sort(p.begin(),p.end());
    for(ll i=0,j=n-1;i<j;){
        while(i<j&&p[i]+p[j]>x) j--;
        if(i>=j) break;
        // cnt is the number of pair 
        cnt++, i++, j--;
    }
    cout << n-cnt << endl;
    
    return 0;
} 

// 15
// 9 8 8 9 10 8 5 8 7 10
// 5 7 8 8 8 8 9 9 10 10
// 10 5
// 10 
// 9
// 9
// 7 8
// 8
// 8
// 8