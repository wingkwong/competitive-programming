#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	int N; cin >> N;
	string S; cin >> S;
	map<pair<int, int>, int> v;
	int l = - 1, r = N;
	pair<int, int> cur = {0, 0};
	v[cur] = 0;
	for(int i = 0; i < N; ++i) {
		if(S[i] == 'L') --cur.first;
		if(S[i] == 'R') ++cur.first;
		if(S[i] == 'U') --cur.second;
		if(S[i] == 'D') ++cur.second;
		if(v.count(cur)) {
			if(i - v[cur] + 1 < r - l + 1) {
				l = v[cur], r = i;
			}
		}
		v[cur] = i + 1;
	}
	if(l == -1) cout << -1 << endl;
	else cout << l + 1 << " " << r + 1 << endl;
}

int main()
{
    FAST_INP;
    int T; cin >> T;
    while (T--) solve();
    // solve();
    return 0;
}
