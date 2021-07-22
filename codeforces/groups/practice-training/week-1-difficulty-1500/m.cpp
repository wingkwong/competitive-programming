#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	int N; cin >> N;
	int max_val = -2e9, max_drop = 0;
	vector<int> A(N);
	for(int &x : A) {
		cin >> x;
		max_val = max(max_val, x);
		max_drop = max(max_drop, max_val - x);
	}
	long long ans = 0;
	while((1LL << ans) - 1 < max_drop) ans++; 
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