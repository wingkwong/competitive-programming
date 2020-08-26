/*
Educational Codeforces Round 92 (Rated for Div. 2) - C. Good String
https://codeforces.com/contest/1389/problem/C
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	// tkt1t2...tk-1 and t2t3...tkt1
	// so tk=t2, t1=t3, t2=t4 ...
	// even length: ABABABAB
	// odd length: AAAAA
	// brute force all possible combinations
    string s;
    cin >> s;
    int ans = 0;
    for (char i = '0'; i <= '9'; i++) {
        for (char j = '0'; j <= '9'; j++) {
        	char x=i, y=j;
            int cnt = 0;
            for(char c:s){
            	if(c==x){
            		cnt++;
            		swap(x,y);
				}
			}
			if(i==j) ans=max(ans,cnt);
			// if the cnt is odd and i!=j, cnt=cnt--;
			else ans=max(ans,cnt&~1);
        }
    }
    cout << (s.size() - ans) << endl;
}

int main() {
    FAST_INP;
    int t;
    string s;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
