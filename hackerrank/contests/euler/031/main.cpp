#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int mxN = 1e5 + 5, mod = 1e9 + 7;
int dp[mxN];

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
    dp[0] = 1;
    for(int i = 0; i < 8; i++) {
        for(int j = coins[i]; j <= mxN; j++) {
            dp[j] += dp[j - coins[i]];
            dp[j] %= mod;
        }
    }
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        cout << dp[x] << "\n";
    }
    return 0;
}
