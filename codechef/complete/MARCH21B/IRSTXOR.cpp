#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	int64_t C; cin >> C;
	int64_t S = 0, P = 1;
	while(C >= S) S = pow(2, P), P++;
	P -= 2;
	int64_t A = pow(2, P) - 1;
	int64_t B = A + S - C;
	cout << A * B << endl;
}

int main()
{
    FAST_INP;
    int T; cin >> T;
    while (T--) solve();
    return 0;
}


