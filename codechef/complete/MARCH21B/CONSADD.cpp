#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	int R, C, X; cin >> R >> C >> X;
	vector<vector<int>> A(R, vector<int>(C)), B(R, vector<int>(C));
	for(int i = 0; i < R; ++i) for(int j = 0; j < C; ++j) cin >> A[i][j];
	for(int i = 0; i < R; ++i) for(int j = 0; j < C; ++j) cin >> B[i][j];
	for(int i = 0; i < R; ++i) for(int j = 0; j <= C - X; ++j)
	{ int diff = A[i][j] - B[i][j]; for(int k = j; k < j + X; ++k) A[i][k] -= diff; }
	for(int i = 0; i < C; ++i) for(int j = 0; j <= R - X; ++j)
	{ int diff = A[j][i] - B[j][i]; for(int k = j; k < j + X; ++k) A[k][i] -= diff; }
	cout << (A == B ? "Yes" : "No") << endl;
}

int main()
{
    FAST_INP;
    int T; cin >> T;
    while (T--) solve();
    // solve();
    return 0;
}
