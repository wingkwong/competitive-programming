#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	int N; cin >> N;
	int ANS = 0;
	int64_t P = 0; // Prefix Sum
	set<int64_t> S;
	S.insert(P);
	// A : 1 -5 3 2
	// P : 0  1 -4 -1 1
	for(int i = 0; i < N; ++i) {
		int A; cin >> A;
		P += A;
		if(S.find(P) != S.end()) {
			ANS++;
			S.clear();
			S.insert(0);
			P = A;
		}
		S.insert(P);
	}
	cout << ANS << endl;
}

int main()
{
    FAST_INP;
    // int T; cin >> T;
    // while (T--) solve();
    solve();
    return 0;
}

