#include <bits/stdc++.h>
using namespace std;

int ds(int x) {
	int res = 0;
	while(x) {
		res += x % 16;
		x /= 16;
	}
	return res;
}

int main() {
	int t; cin >> t;
	while(t--) {
		int l, r; 
		cin >> l >> r;
		int ans = 0;
		for(int i = l; i <= r; i++) {
			ans += (gcd(ds(i), i) > 1);
		}
		cout << ans << endl;
	}
	return 0;
}