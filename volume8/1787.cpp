/*
Volume 8 - 1787. Turn for MEGA
https://acm.timus.ru/problem.aspx?space=1&num=1787
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    ll n,m,a,cnt=0;
    cin >> n >> m;
    for(int i=0;i<m;i++){
    	cin >> a;
    	cnt+=a;
    	if(cnt-n>=0) cnt-=n;
    	else cnt=0;
	}
	cout << cnt << endl;
    return 0;
} 




