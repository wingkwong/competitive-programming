#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int go(string s, int i, int j) {
	int res = 0;
	// even length : ABABABAB
	// odd length  : AAAAAAAA
	for(auto c : s) {
		if(c - '0' == i) {
			res++;
			swap(i, j);
		}
	}
	if(i != j && res & 1) res--;
	return res;
}


void solve() {
	string S; cin >> S;
	int N = (int) S.size(), ans = 0;
	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < 10; ++j) {
			ans = max(ans, go(S, i, j));
		}
	}
	cout << N - ans << endl;
}

int main()
{
    FAST_INP;
    int T; cin >> T;
    while (T--) solve();
    // solve();
    return 0;
}
