#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	int N; cin >> N;
	vector<int> A(N + 1), B(N + 1), ANS(N + 1);
	for(int i = 1; i <= N; ++i) cin >> A[i];
	long long S = 0;
	for(int i = 1; i <= N; ++i) {
		long long C = 0;
		B[i] = A[i];
		for(int j = i - 1; j >= 1; --j) B[j] = min(A[j], B[j + 1]);
		for(int j = i + 1; j <= N; ++j) B[j] = min(A[j], B[j - 1]);
		for(int j = 1; j <= N; ++j) C += B[j];
		if(C > S) {
			S = C;
			ANS = B;
		}
	}
	for(int i = 1; i <= N; ++i) cout << ANS[i] << " \n"[i == N];
}

int main()
{
    FAST_INP;
    // int T; cin >> T;
    // while (T--) solve();
    solve();
    return 0;
}