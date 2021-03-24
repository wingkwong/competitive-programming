#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	int N, K;
	cin >> N >> K;
	int A = 1, B = K;
	for(int i = 1; i <= K; ++i) {
		// [1, K - (N - K) - 1]
		if(i < 2 * K - N) cout << A++;
		// [K - (N - K), K]
		else cout << B--;
		cout << " \n"[i == K];
	}
}

int main()
{
    FAST_INP;
    int T; cin >> T;
    while (T--) solve();
    // solve();
    return 0;
}
