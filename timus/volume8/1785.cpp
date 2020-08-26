/*
Volume 8 - 1785. Lost in Localization
https://acm.timus.ru/problem.aspx?space=1&num=1785
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
    if(n>=1&&n<=4) cout << "few" << endl;
    else if(n>=5&&n<=9) cout << "several" << endl;
    else if(n>=10&&n<=19) cout << "pack" << endl;
    else if(n>=20&&n<=49) cout << "lots" << endl;
    else if(n>=50&&n<=99) cout << "horde" << endl;
    else if(n>=100&&n<=249) cout << "throng" << endl;
    else if(n>=250&&n<=499) cout << "swarm" << endl;
    else if(n>=500&&n<=999) cout << "zounds" << endl;
    else if(n>=1000) cout << "legion" << endl;
    return 0;
} 
