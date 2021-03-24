#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

bool ok(int n, int d) {
	long long sum = 1LL * n * (n + 1) / 2;
	if(sum < d) return false;
	return sum % 2 == d % 2;
}

void solve() {
	int A, B;
	cin >> A >> B;
	int d = abs(A - B);
	if(d == 0) {
		cout << 0 << endl;
		return;
	}
	int ans = 1;
	while(!ok(ans, d)) ++ans;
	cout << ans << endl;
}

void solve2() {
	int A, B;
	cin >> A >> B;
	long long D = abs(A - B), S = 0, M = 0;
	while(S < D || S % 2 != D % 2) S += ++M;
	cout << M << endl;
}

int main()
{
    FAST_INP;
    int T; cin >> T;
    while (T--) solve2();
    // solve();
    return 0;
}
