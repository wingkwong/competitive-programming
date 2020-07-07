#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    long long n,ans=0;
    cin >> n;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin >> x[i];
    for(int i=1;i<n;i++){
    	// if x[i] is smaller than the previous one 
    	if(x[i]<x[i-1]) {
    		// then x[i] needs x[i-1]-x[i] to be at least as large as the previous element
    		ans+=x[i-1]-x[i];
    		// update x[i]
    		x[i]=x[i-1];
		}
	}
	cout << ans << "\n";
    return 0;
} 
