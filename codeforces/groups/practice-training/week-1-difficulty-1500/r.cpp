#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

const int mxN = 200005;
int in[mxN], f[mxN];

void solve() {
	int N; cin >> N;
	vector<pair<int, int>> s;
	for(int i = 1; i <= N; i++) {
		cin >> f[i];
		if(f[i]) in[f[i]] = 1;
	}
	for(int i = 1; i <= N; i++) {
		if(!in[i]) {
			int x = i;
			while(f[x] != 0) x = f[x];
			s.push_back({i, x});
		}
	}
	int sz = (int) s.size();
	for(int i = 0; i < sz; i++) f[s[i].second] = s[(i + 1) % sz].first;
	for(int i = 1; i <= N; i++) cout << f[i] << " \n"[i == N];
}

int main()
{
    FAST_INP;
    // int T; cin >> T;
    // while (T--) solve();
    solve();
    return 0;
}