/*
AtCoder Beginner Contest 172 - D - Sum of Divisors
https://atcoder.jp/contests/abc172/tasks/abc172_d
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n;
    cin >> n;
    vector<long long> d(n+1,0);
    long long ans=0;
    for(int i=1;i<=n;i++){
    	for (int j=1;j*i<=n;j++) {
            // d(X) be the number of positive divisors of X .
    		d[i*j]++; 
		}
	}
    
    for(int i=1;i<=n;i++){
        // find ∑N K=1 K*d(K)
    	ans+=i*d[i];
    } 
    
    cout << ans;
    return 0;
} 
