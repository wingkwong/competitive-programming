#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; 
	cin >> n >> m;
	vector<int> a(n);
	int ans = -1;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		if(x == m) ans = i + 1;
	}
	cout << ans << endl;
	return 0;
}