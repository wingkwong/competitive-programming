/*
Codeforces Testing Round #1 - A. 123-sequence
https://codeforces.com/problemset/problem/52/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,d,a=0,b=0,c=0;
    cin >> t;
    for(int i=0;i<t;i++){
    	cin >> d;
    	if(d==1) a++;
    	else if(d==2) b++;
    	else c++;
	}
	cout << t-max(a,max(b,c));
    return 0;
} 
