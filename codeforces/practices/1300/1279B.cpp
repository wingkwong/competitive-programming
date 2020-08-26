/*
Educational Codeforces Round 79 (Rated for Div. 2) - B. Verse For Santa
https://codeforces.com/problemset/problem/1279/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n,s;
    cin >> t;
    while(t--){
    	cin >> n >> s;
    	vector<int> a(n);
    	for(auto &x:a) cin >> x;
    	int j=0;
    	for(int i=0;i<n;i++){
    		if(a[i]>a[j]) j=i;
    		s-=a[i];
    		if(s<0) break;
		}
		cout << (s>=0?0:j+1) << endl;
	}
    return 0;
} 

