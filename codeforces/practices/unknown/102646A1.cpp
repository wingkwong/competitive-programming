/*
Testing Round #XVII - A1. Product of Triples (Easy Version)
https://codeforces.com/gym/102646/problem/A1
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    int n;
    cin >> n;
    int m[n+1];
    memset(m,0,sizeof(m));
    for(ll i=1;i<=n;i++){
    	for(ll j=i;j<=n;j++){
	    	for(ll k=j;k<=n;k++){
	    		if(i*j*k<=n){
	    			m[i*j*k]++;
				}
			}
		}	
	}
	for(int i=1;i<=n;i++) {
		cout << m[i] << endl;
	}
    return 0;
} 
