/*
Codeforces Round #632 (Div. 2) - B. Kind Anton
https://codeforces.com/contest/1333/problem/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve(){
    // by observation, if a[i] is not same as b[i], we need either 1 or -1 to equalise a[i] and b[i]
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	// if f1=true, we can add b[j] by 1 since a[j]=1 where i<j
	// if f2=true, we can substract b[j] from 1 since a[j]=-1 where i<j
    bool f1=false,f2=false;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++){
    	// if a[i] < b[i], we need 1 to equalise 
    	// if f1=false, then we cannot equalise for this case
    	if(a[i]<b[i]&&!f1){
    		cout << "NO\n";
    		return;
		}
    	// if a[i] > b[i], we need -1 to equalise 
    	// if f2=false, then we cannot equalise for this case
		if(a[i]>b[i]&&!f2){
			cout << "NO\n";
			return;
		}
		
		// found 1
		if(a[i]==1) f1=true;
		// found -1
		if(a[i]==-1) f2=true;
	}
	cout << "YES\n";
}

int main()  
{ 
    FAST_INP;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
} 
