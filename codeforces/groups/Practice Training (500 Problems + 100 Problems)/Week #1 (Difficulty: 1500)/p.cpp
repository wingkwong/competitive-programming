#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

const int mxN = 100;
int T[mxN], L[mxN], H[mxN];

void solve() {
	int N, M; cin >> N >> M;
	for(int i = 0; i < N; i++) cin >> T[i] >> L[i] >> H[i];
	int prev_t = 0, mx = M, mi = M, ok = 1;
	for(int i = 0; i < N; i++) {
		mx += T[i] - prev_t;
		mi -= T[i] - prev_t;
		if(mx < L[i] || mi > H[i]) {
			ok = 0;
			break;
		}
		mx = min(mx, H[i]);
		mi = max(mi, L[i]);
		prev_t = T[i];
	}
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main()
{
    FAST_INP;
    int T; cin >> T;
    while (T--) solve();
    // solve();
    return 0;
}