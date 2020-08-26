/*
AtCoder Beginner Contest 171 - B - Mix Juice
https://atcoder.jp/contests/abc171/tasks/abc171_b
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int n,k; 
    cin >> n >> k;
    vector<int> v(n);
    // read the input
    for(int i=0;i<n;i++) cin >> v[i];
    // sort the input
    sort(v.begin(),v.end());
    int ans=0;
    // sum the first k items up
    for(int i=0;i<k;i++){
    	ans+=v[i];
	}
	cout << ans << endl;
    return 0;
} 
