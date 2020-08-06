/*
Codeforces Round #661 (Div. 3) - A. Remove Smallest
https://codeforces.com/contest/1399/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    // if |ai-aj|=1 cannot be fulfilled, then the ans is NO
    // hence, sort the input and check if a[i]-a[i-1]>1
    // if so, print NO
    // else, print YES
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(),a.end());
        int ok=1;
        for(int i=1;i<n;i++){
        	if(a[i]-a[i-1]>1) {
        		ok=0;
        		break;
			}
		}
		if(ok) cout << "YES\n";
		else cout << "NO\n";
    }
    return 0;
} 
