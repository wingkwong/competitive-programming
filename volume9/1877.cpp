/*
Volume 9 - 1877. Bicycle Codes
https://acm.timus.ru/problem.aspx?space=1&num=1877
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
	// first: even
	// second: odd
    cout << ((a%2==0||b&1)?"yes":"no") << endl;
    return 0;
} 

