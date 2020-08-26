/*
Volume 11 - 2001. Mathematicians and Berries
https://acm.timus.ru/problem.aspx?space=1&num=2001
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    ll a1,b1,a2,b2,a3,b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    //berriesA = x
	//berriesB = y
	//basketA  = a1-x = a3
	//basketB  = b1-y = b2
    cout << a1-a3 << " " << b1-b2 << endl;
    return 0;
} 




