#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll sum = 0, a = 1, b = 2, c;
        while(b <= n) {
            sum += ((b & 1) ^ 1) ? b : 0;
            c = a + b;
            a = b;
            b = c; 
        }
        cout << sum << "\n";
    }
    return 0;
}
