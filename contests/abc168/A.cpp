/*
A - ? (Therefore)
https://atcoder.jp/contests/abc168/tasks/abc168_a
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int t; 
    string ans="";
    cin >> t;
    while(t){
    	// checking each digit to see if it matches the requirement
    	// if it does, set the ans and break the loop
    	// if not, check the next digit
    	int x=t%10;
    	if(x==2||x==4||x==5||x==7||x==9) ans="hon";
    	else if(x==0||x==1||x==6||x==8) ans="pon";
    	else if(x==3) ans="bon";
    	if(ans!="") break;
    	t/=10;
	}
	cout << ans << "\n";
    return 0;
} 
