/*
C - : (Colon)
https://atcoder.jp/contests/abc168/tasks/abc168_c
*/
#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int a,b,h,m;
    long double PI=acos(-1);
    cin >> a >> b >> h >> m;
    // use law of cosines to find out the third side c
    // c^2 = a^2+b^2-2abcosC
	long double rad = 2*PI*( (long double)h/12.0 + ((long double)m/60.0)/12.0 - (long double)m/60.0);
    cout << setprecision(20) << sqrtl((long double)(a*a+b*b)-(long double)(2*a*b)*cosl(rad)) << "\n";
    return 0;
} 

