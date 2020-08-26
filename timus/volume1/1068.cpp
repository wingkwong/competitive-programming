/*
Volume 1 - 1068. Sum
https://acm.timus.ru/problem.aspx?space=1&num=1068
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    ll n;
    cin >> n;
    if(n>0) cout << n*(n+1)/2 << endl;
    else cout << (-1*(-n*(-n+1)/2))+1 << endl;
    return 0;
} 


