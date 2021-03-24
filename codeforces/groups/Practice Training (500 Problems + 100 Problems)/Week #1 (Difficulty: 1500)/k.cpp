#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	int A, B, C;
	cin >> A >> B >> C;
	// A : 00 00
	// B : 01 10
	// C : 11 11
	if(B == 0) {
		if(A != 0) cout << string(A + 1, '0') << endl;
		else cout << string(C + 1, '1') << endl;
	} else {
		string S;
		// 1 3 5
		// 1010 -> satisfy B
		// 10010 -> satisfy A
		// 1111110010 satisfy C
		for(int i = 0; i < B + 1; ++i) S += (i & 1 ? '0' : '1');
		S.insert(1, string(A, '0'));
		S.insert(0, string(C, '1'));
		cout << S << endl;
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