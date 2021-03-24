#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	int N; cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; ++i) cin >> A[i];
	sort(A.begin(), A.end());
	// 1 2 3 4
	int r = 0;
	long long ans = 0;
	for(int i = 0; i < N; ++i) {
		while(A[r + 1] - A[i] <= 2 && r + 1 < N) r++;
		// (r - i) choose 2 
		if(r - i >= 2) ans += (long long) (r - i) * (r - i - 1) / 2;
	}
	cout << ans << endl;
}

int main()
{
    FAST_INP;
    int T; cin >> T;
    while (T--) solve();
    // solve();
    return 0;
}
