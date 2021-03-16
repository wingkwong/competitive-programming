#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MIN(a, b) a=min<ll>(a, b)

ll go(ll N, ll E, ll H, ll A, ll B, ll C) {
	if(N <= 0) return 0;
	// E eggs 
	// H chocolate bars
	// ----------------------
	// 2 eggs to make an omelette
	// 3 chocolate bars for a chocolate milkshake
	// 1 egg and 1 chocolate bar for a chocolate cake
	ll ans = 1E16;
	if(N <= E / 2) MIN(ans, A * N);
	if(N <= H / 3) MIN(ans, B * N);
	if(N <= E && N <= H) MIN(ans, C * N);
	if((H - N) / 2 >= 1 && (H - N) / 2 >= N - E) MIN(ans, (B - C) * (B < C ? min(N - 1, (H - N) / 2) : max(N - E, 1LL)) + C * N);
	if(E >= N + 1 && E + H >= N * 2) MIN(ans, (A - C) * (A < C ? min(N - 1, E - N) : max(N - H, 1LL)) + C * N);
	if(E >= 2 && (N - (E / 2)) * 3 <= H) MIN(ans, (A - B) * (A < B ? min(N - 1, E / 2) : max(N - (H / 3), 1LL)) + B * N);
	if(N >= 3 && E >= 3 && H >= 4) MIN(ans, A + B + C + go(N - 3, E - 3, H - 4, A, B, C));
	return ans;
}

void solve() {
	ll N, E, H, A, B, C;
	cin >> N >> E >> H >> A >> B >> C;
	ll ans = go(N, E, H, A, B, C);
	cout << (((N > E && N > H) || ans == 1E16) ? -1 : ans) << endl;
}

int main()
{
    FAST_INP;
    int T; cin >> T;
    while (T--) solve();
    return 0;
}