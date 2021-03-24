#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	long long N, K; cin >> N >> K;
	string S; cin >> S;
	int x = 0; // first zero 
	int y = 0; // first one
	while(x < N && S[x] == '0') x++, y++;
	for(int i = y; i < N; i++) {
		if(S[i] == '0') {
			if(i - x < K) {
				swap(S[i], S[x]);
				K -= (long long)(i - x);
				x++;
			} else {
				swap(S[i], S[i - K]);
				cout << S << endl;
				return;
			}
		}
	}
	cout << S << endl;
}

int main()
{
    FAST_INP;
    int T; cin >> T;
    while (T--) solve();
    // solve();
    return 0;
}