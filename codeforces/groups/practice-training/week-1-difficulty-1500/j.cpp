#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	int N; cin >> N;
	vector<int> A(N);
	for(auto &a : A) {
		cin >> a;
		a--;
	}
	if(is_sorted(A.begin(), A.end())) {
		cout << 0 << endl;
		return;
	}
	int l = 0, r = N;
	while(l < r && A[l] == l) l++;
	while(r > l && A[r - 1] == r - 1) r--;
	int has_fixed_pt = 0;
	for(int i = l; i < r; i++) {
		if(A[i] == i) {
			has_fixed_pt = 1;
		}
	} 
	cout << (has_fixed_pt ? 2 : 1) << endl;
}

int main()
{
    FAST_INP;
    int T; cin >> T;
    while (T--) solve();
    // solve();
    return 0;
}
