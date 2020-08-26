/*
Testing Round #XVII - A2. Product of Triples (Hard Version)
https://codeforces.com/gym/102646/problem/A2
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
    // a<=b<=c 
    // a*b*c<=n
    // the upper bound of a: a^(1/3)<=n 
    // the upper bound of b: b^(1/2)<=n
    for(ll i=1;i<=22;i++){
    	for(ll j=i;j<=100;j++){
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
