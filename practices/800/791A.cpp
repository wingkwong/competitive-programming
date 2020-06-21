/*
Codeforces Round #405 (rated, Div. 2, based on VK Cup 2017 Round 1) - A. Bear and Big Brother
https://codeforces.com/problemset/problem/791/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int a,b,ans=0;
    cin >> a >> b;
    while(a<=b){
    	a*=3;
    	b*=2;
    	ans++;
	}
	cout << ans << "\n";
    return 0;
} 
