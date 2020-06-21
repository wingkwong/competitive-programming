/*
AtCoder Beginner Contest 169 - B - Multiplication 2
https://atcoder.jp/contests/abc169/tasks/abc169_b
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int n;
    long long a,ans=1,m=(long long)1e18; 
    cin >> n;
    bool f=false;
    for(int i=0;i<n;i++){
    	cin >> a;
		// if the input is zero, the ans must be 0
    	if(a==0){
    		ans=0;
    		f=false;
			break;
		}	
    	if(!f){
			// cannot compare 1e18 with the input directly 
			// m/ans<a = a*ans>=m
    		if(m/ans<a) {
	    		f=true;
			}
	    	ans*=a;
		}
	}
	// exceed 1e18
	if(f) ans=-1;
	
	cout << ans << endl;
    return 0;
} 