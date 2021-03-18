#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	int A, B; cin >> A >> B;
	int ans = 0, socket = 1;
	while(socket < B) {
		--socket; // use once socket for a power strip
		socket += A; // a power strip gives A sockets
		ans++;
	}
	cout << ans << endl;
}

int main()
{
    FAST_INP;
    // int T; cin >> T;
    // while (T--) solve();
    solve();
    return 0;
}