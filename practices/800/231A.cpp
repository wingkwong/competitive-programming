/*
Codeforces Round #143 (Div. 2) - A. Team
https://codeforces.com/problemset/problem/231/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,ans=0,a,b,c;
    cin >> n;
    while(n--){
    	cin >> a >> b >> c;
    	if(a+b+c>=2) ans++;
	}
	cout << ans << "\n";
    return 0;
} 

