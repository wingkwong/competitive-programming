#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

const string t = "abacaba";

void solve() {
	int N; cin >> N;
	string S; cin >> S;
	auto check = [&](string s) {
		int res = 0;
		for(int i = 0; i < N - 6; ++i) res += s.substr(i, 7) == t;
		return res == 1;
	};
	for(int i = 0; i < N - 6; ++i) {
		string ss = S;
		for(int j = 0; j < 7; j++) {
			if(ss[i + j] == '?') {
				ss[i + j] = t[j];
			}
		}
		if(check(ss)) {
			cout << "Yes" << endl;
			for(char c : ss) {
				if(c == '?') cout << 'd';
				else cout << c;
			}
			cout << endl;
			return;
		}
	}
	cout << "No" << endl;
}

int main()
{
    FAST_INP;
    int T; cin >> T;
    while (T--) solve();
    // solve();
    return 0;
}
