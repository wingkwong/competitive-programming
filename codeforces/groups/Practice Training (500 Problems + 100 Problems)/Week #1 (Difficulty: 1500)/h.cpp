#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	long long L, R, M; 
	cin >> L >> R >> M;
	// N * A + (B - C) = M
	// N * A + X = M
	// X = [L - R, R - L]
	long long mi = L - R, mx = R - L;
	for(int i = L; i <= R; i++) {
		long long SUB = M % i; // the extra value to substract from M to make it divisible by A 
		long long ADD = i - SUB; // the extra value to add to M to make it divisible by A
		if(SUB <= mx && M - SUB != 0) {
			cout << i << " " << L + SUB << " " << L << endl; 
			return;
		}
		if(ADD <= mx) {
			cout << i << " " << L << " " << L + ADD << endl; 
			return;
		}
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
