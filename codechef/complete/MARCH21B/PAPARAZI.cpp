#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	int N; cin >> N;
	vector<int> H(N);
	vector<pair<int, int>> v;
	for(int i = 0; i < N; ++i) {
		cin >> H[i];
		v.push_back({i + 1, H[i]});
	}
	if(N <= 2) {
		cout << 1 << endl;
		return;
	}
	deque<pair<int, int>> d;
	for(int i = 0; i < 2; i++) d.push_back(v[i]);
	int M = (int) d.size(), ans = 1;
	for(int i = 2; i <= N; i++) {
		while(M >= 2) {
			double slope1 = (double)(d[M - 1].second - d[M - 2].second) / (d[M - 1].first - d[M - 2].first);
			double slope2 = (double)(v[i].second - d[M - 1].second) / (v[i].first - d[M - 1].first);
			// cout << slope1 << " " << slope2 << endl;
			if(slope1 > slope2) break;
			d.pop_back();
			M--;
		}
		d.push_back(v[i]);
		M++;
		ans = max(ans, d[M - 1].first - d[M - 2].first);
	}
	cout << ans << endl;
}

int main()
{
    FAST_INP;
    int T; cin >> T;
    while (T--) solve();
    return 0;
}


