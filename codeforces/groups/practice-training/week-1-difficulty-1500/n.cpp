#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> A(N), B(M);
	for(auto &x : A) cin >> x;
	for(auto &x : B) cin >> x;
	vector<int> C;
	for(int i = 1; i * i <= K; ++i) {
		if(K % i == 0) {
			C.push_back(i);
			if(K / i != i) C.push_back(K / i);
		}
	}
	long long z = (int) C.size(), ans = 0;
	for(int i = 0; i < z; ++i) {
		long long p = 0, q = 0, cnt = 0;
		for(int j = 0; j < N; j++) {
			if(A[j] == 1) cnt++;
			else cnt = 0;
			if(cnt >= C[i]) p++; 
		}
		cnt = 0;
		for(int j = 0; j < M; j++) {
			if(B[j] == 1) cnt++;
			else cnt = 0;
			if(cnt >= (K / C[i])) q++; 
		}
		ans += 1LL * p * q;
	}
	cout << ans << endl;
}

int main()
{
    FAST_INP;
    // int T; cin >> T;
    // while (T--) solve();
    solve();
    return 0;
}