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
    vector<int> a(n), b(n);
    for(auto &k:a) cin >> k;
    for(auto &k:b) cin >> k;
    int i=0, j=0;
    while(i<n||j<n){
    	if(i>=n) cout << b[j++];
    	else if(j>=n) cout << a[i++];
    	else if(a[i]<=b[j]) cout << a[i++];
    	else cout << b[j++];
    	cout << " ";
	}
    return 0;
} 
