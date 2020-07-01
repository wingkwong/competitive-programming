/*
Codeforces Round #577 (Div. 2) - A. Important Exam
https://codeforces.com/problemset/problem/1201/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,m,ans=0;
    string s;
    cin >> n >> m;
	vector<vector<int>> c(m,vector<int>(5,0));
	vector<int> a(m,0);
    for(int i=0;i<n;i++){
		cin >> s;
		for(int j=0;j<m;j++) c[j][s[j]-'A']++;
	}
	for(int i=0;i<m;i++) cin >> a[i];
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			cout << c[i][j] << " " ;
//		}
//		cout << endl;
//	}
	for(int i=0;i<m;i++) ans+=a[i]*max({c[i][0],c[i][1],c[i][2],c[i][3],c[i][4]});
	cout << ans << endl;
    return 0;
} 
