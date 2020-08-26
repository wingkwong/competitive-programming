/*
Codeforces Round #642 (Div.3 ) - B. Two Arrays And Swaps
https://codeforces.com/contest/1353/problem/B
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n,k;
    cin >> t;
    while(t--){
    	cin >> n >> k;
		vector<int> a(n),b(n); 
    	int asum=0;
    	// read the input a1..an
    	for(int i=0;i<n;i++) {
    		cin >> a[i];
    		// calculate the sum here
    		asum+=a[i];
		}
		// read the input b1..bn
    	for(int i=0;i<n;i++) cin >> b[i];
    	// if k is 0, no swaps can be performed
    	// output the sum of a1..an and continue
    	if(k==0) {
    		cout << asum << "\n";
    		continue;
		}
		// sort a in an ascending order
		sort(a.begin(),a.end());
		// sort b in a descending order
		sort(b.rbegin(),b.rend());
		// two pointers
		int i=0,j=0;
		// perform the following action when we can still swap and i & j are not out of boundary
		while(k--&&i<n&&j<n){
			// as we sorted a&b, if b[j] <= a[i], that means b[j+1..n-1] <= a[i+1..n-1]
			// so no swaps can be performed here
			if(b[j]<=a[i]) break;
			// or else, update a[i] and the pointers i & j
			a[i++]=b[j++];
		}
		// reset asum
		asum=0;
		// re-calcucate the sum
		for(int i=0;i<n;i++) asum+=a[i];
		cout << asum << "\n";
	}
    return 0;
} 
