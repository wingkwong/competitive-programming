#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    long long n,d,sum=0; 
    cin >> n;
	for(int i=0;i<n-1;i++) {
		cin >> d;
		sum+=d;
	}
	// n*(n+1)/2 - find the sum of 1..n
	// ans = the sum of 1..n - the sum of input
	cout << n*(n+1)/2 - sum  << "\n";
    return 0;
} 
