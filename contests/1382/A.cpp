/*
Codeforces Round #658 (Div. 2) - A. Common Subsequence
https://codeforces.com/contest/1382/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)


bool solve(){
    // find the first common element k and return 
    // YES
    // 1 k 
    // else return NO
	int a,b;
	cin >> a >> b;
    vector<int> aa(a);
    vector<int> bb(b);
    for(int i=0;i<a;i++) cin >> aa[i];
    for(int i=0;i<b;i++) cin >> bb[i];
	for(int i=0;i<b;i++){
    	if(find(aa.begin(), aa.end(), bb[i])!=aa.end()){
    		cout << "YES\n";
    		cout << 1 << " " << bb[i] << "\n";
    		return true;
		}
	}
	cout << "NO\n";
	return false;
}

int main()  
{ 
    FAST_INP;
    int n,t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
} 
