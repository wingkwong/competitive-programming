#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

const int mxN = 1e6 + 5;
const int M = 1e9 + 7;
long long f[mxN], p[mxN];


void solve() {
	int N; cin >> N;
	f[1] = 1;
	long long bad = 1;
	for(int i = 2; i <= N; ++i) {
		f[i] = (f[i - 1] * i) % M;
		bad = (bad * 2) % M;
	}
	// N! - 2^{N - 1}
	cout << ((f[N] - bad + M) % M) << endl;
}

int main()
{
    FAST_INP;
    // int T; cin >> T;
    // while (T--) solve();
    solve();
    return 0;
}
