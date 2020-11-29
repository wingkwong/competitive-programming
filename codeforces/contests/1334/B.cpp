/*
Educational Codeforces Round 85 (Rated for Div. 2) - B. Middle Class
https://codeforces.com/contest/1334/problem/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,x,t;
    cin >> t;
    while(t--){
        cin >> n >> x;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >>a[i];
		// sort by descending order
        sort(a.rbegin(),a.rend());
        long long sum=0;
        int idx=0;
        for(int i=0;i<n;i++){
			// if a[i] can be deducted, deduct it
        	if(a[i]>=x){
        		sum+=a[i]-x;
			}else{
				// if the largest number is smaller than x, set idx=-1
				// if not, idx is the last idx of the number that can be deducted
				idx=(i==0?-1:i);
				break;
			}
		}

		// the largest number is smaller than x
		if(idx==-1){
			cout << 0 << "\n";
        	continue;
		}
		// all numbers are greater than / equal to x
        if(idx==0) {
        	cout << n << "\n";
        	continue;
		}
		int idx2=0;
		// start from idx
		for(int i=idx;i<n;i++){
			// if the number can be added, add it up to x
			if(sum>=x-a[i]) {
				idx2++;
				sum-=x-a[i];
			}else{
				break;
			}
		}
		cout << idx+idx2 << "\n";
    }
    return 0;
} 
