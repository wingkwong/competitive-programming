/*
Hello 2019 - B. Petr and a Combination Lock
https://codeforces.com/problemset/problem/1097/B
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
    vector<int> a(n);
    for(int &x:a) cin >> x;
	for(int mask=0;mask<(1<<n);mask++){
		int ans=0;
		for(int i=0;i<n;i++){
			if(mask&(1<<i)) ans+=a[i];
			else ans-=a[i];
		}
		if(ans%360==0) {
			cout << "YES\n";
			return 0;
		}
	} 
	cout << "NO\n";
    return 0;
}  
