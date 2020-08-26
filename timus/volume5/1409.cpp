/*
Volume 5 - 1409. Two Gangsters
https://acm.timus.ru/problem.aspx?space=1&num=1409
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    ll a,b;
    cin >> a >> b;
    // sum=a+b-1
    // a: sum-a = (a+b-1)-a = b-1
    // b: sum-b = (a+b-1)-b = a-1
    cout << b-1 << " " << a-1 << endl;
    return 0;
} 

//x x x x 
//      x x x x x x x
