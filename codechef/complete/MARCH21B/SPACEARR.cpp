#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	int N; cin >> N;
	vector<int> A(N + 1);
	for(int i = 1; i <= N; ++i) cin >> A[i];
	sort(A.begin(), A.end());
	int cnt = 0;
	for(int i = 1; i <= N; ++i) {
		if(A[i] > i) {
			cout << "Second" << endl;
			return;
		} 
		cnt += i - A[i];
	}
	cout << (cnt & 1 ? "First" : "Second") << endl;
}

int main()
{
    FAST_INP;
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
