/*
빠른 A+B
https://www.acmicpc.net/problem/15552
*/

#include <bits/stdc++.h>
using namespace std;

#define TC(t) while (t--)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)


void solve() {
	int a, b;
	cin >> a >> b;
	cout << a + b << "\n";
}

int main()
{
    FAST_INP;
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt","r", stdin);
//    freopen("output.txt","w", stdout);
//    #endif

    int tc; cin >> tc;
    TC(tc) solve();
    // solve();
    return 0;
}
