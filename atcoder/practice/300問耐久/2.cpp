#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	int N; cin >> N;
	vector<int> X(N);
	for(int &x : X) cin >> x;
	int P = 1e9;
	for(int i = 1; i <= 100; ++i) { // 1 <= X[i] <= 100
		int cost = 0;
		for(int j = 0; j < N; ++j) cost += (X[j] - i) * (X[j] - i);
		P = min(P, cost);
	}
	cout << P << endl;
}

int main()
{
    FAST_INP;
    // int T; cin >> T;
    // while (T--) solve();
    solve();
    return 0;
}