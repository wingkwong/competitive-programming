#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int sum(long long n) {
	int res = 0;
	while(n > 0) res += n % 10, n /= 10;
	return res;
}

void solve() {
	long long N; cin >> N;
	int S; cin >> S;
	if(sum(N) <= S) {
		cout << 0 << endl;
		return;
	}
	long long P = 1, ans = 0 ;
	for(int i = 0; i < 18; i++) {
		int D = (N / P) % 10;
		long long A = P * ((10 - D) % 10);
		N += A;
		ans += A;
		if(sum(N) <= S) {
			break;
		}
		P *= 10;
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
