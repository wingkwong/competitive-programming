/*
Codeforces Round #663 (Div. 2) - A. Suborrays
https://codeforces.com/contest/1391/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        if(n==1){
        	cout << 1 << endl;
        	continue;
		}
        int cnt=0,i=1,j=n;
        while(cnt!=n){
        	if(j<=1&&i>=n-1) break;
        	if(j>1&&j>n/2) cout << j << " ", cnt++;
        	if(i<n&&i<n/2+1) cout << i << " ", cnt++;
        	j--,i++;
		}
		cout << endl;
		
		/*
			Every permutation is good.
			The shortest solution is 
			for(int i=1;i<=n;i++) cout << i << " ";
			cout << endl;
		*/
    }
    return 0;
} 

