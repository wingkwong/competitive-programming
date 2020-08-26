/*
Codeforces Round #659 (Div. 2) - A. Common Prefixes
https://codeforces.com/contest/1384/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

// WA - Wrong answer on test 32
//void solve(){
//	cin >> n;
//    vector<int> v(n);
//    int mx=0;
//    for(int i=0;i<n;i++){
//    	cin >> v[i];
//    	mx=max(v[i],mx);
//	}
//	if(mx==0) mx=1;
//	string s1(150,'a');
//	int j=1;
//	cout << s1 << endl;
//	for(int i=0;i<n;i++){
//		string s2(150-v[i],(char)(j++%26)+97);
//		s2=s1.substr(0,v[i])+s2; 
//		cout << s2 << endl;
//		s1=s2;
//	}
//}

void solve(){
	int n, a; cin >> n;
	string s(150,'a');
	cout << s << endl;
	for(int i=0;i<n;i++){
		cin >> a;
		s[a] = s[a]=='a'?'b':'a';
		cout << s << endl;
	}
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
