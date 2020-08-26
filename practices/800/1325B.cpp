/*
Codeforces Round #628 (Div. 2) - B. CopyCopyCopyCopyCopy
https://codeforces.com/problemset/problem/1325/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n,a;
    cin >> t;
    while(t--){
    	cin >> n;
    	unordered_set<int> s;
    	for(int i=0;i<n;i++){
    		cin >> a;
    		s.insert(a);
		}
		cout << s.size() << endl;
	}
    return 0;
} 
