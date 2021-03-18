#include <bits/stdc++.h>
using namespace std;
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	int N, A, B; 
	string S; // a : japanese ; b : overseas ; c : neither
	cin >> N >> A >> B >> S;
	int passed = 0, passed_b = 0;
	for(char c : S) {
		int is_pass = 0;
		if(c == 'a') {
			if(passed < A + B) {
				is_pass = 1;
				passed++;
			} 
		} else if(c == 'b') {
			if(passed < A + B && passed_b < B) {
				is_pass = 1;
				passed++;
				passed_b++;
			}
		} 
		if(is_pass) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}

int main()
{
    FAST_INP;
    // int T; cin >> T;
    // while (T--) solve();
    solve();
    return 0;
}