/*
AtCoder Beginner Contest 174 - D - Alter Altar
https://atcoder.jp/contests/abc174/tasks/abc174_d
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    // change it to sequence like
    // RRRRR..RWWWW..W
    int n;
    cin >> n;
    string s;
    cin >> s;
	int r=0, w=0, swap=0;
	for (int i=0;i<n;i++) {
		if(s[i]=='W') w++;
		else r++;
	}
	int ans = min(w,r);
	for (int i=0;i<r;i++) {
		if(s[i]=='W') swap++;
	}
	ans=min(ans,swap);
	cout << ans << endl;
    return 0;
} 
