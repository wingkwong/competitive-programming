#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	string S; int X;
	cin >> S >> X;
	int N = (int) S.size();
	string A(N, '1');
	for(int i = 0; i < N; ++i) {
		if(S[i] == '0') {
			if(i - X >= 0) {
				A[i - X] = '0';
			}
			if(i + X <= N - 1) {
				A[i + X] = '0';
			}
		}
	}
	for(int i = 0; i < N; ++i) {
		int ok = 0;
		ok |= (i - X >= 0 && A[i - X] == '1');
		ok |= (i + X <= N - 1 && A[i + X] == '1');
		if(S[i] != ok + '0') {
			cout << -1 << endl;
			return;
		}
	}
	cout << A << endl;
}

int main()
{
    FAST_INP;
    int T; cin >> T;
    while (T--) solve();
    // solve();
    return 0;
}
