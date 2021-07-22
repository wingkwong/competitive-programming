#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	int N; cin >> N;
	vector<int> A(N);
	unordered_map<int, int> m;
	for(int &x : A) {
		cin >> x;
		m[x]++;
	}
	int ans = 0;
	for(int i = 0; i < N; ++i) {
		int sum = A[i];
		for(int j = i + 1; j < N; j++) {
			sum += A[j];
			if(sum <= N) {
				ans += m[sum];
				m[sum] = 0;
			}
		}
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