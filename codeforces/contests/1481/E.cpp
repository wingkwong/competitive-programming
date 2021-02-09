/*
Codeforces Round #699 (Div. 2) - E. Sorting Books
https://codeforces.com/contest/1481/problem/E
*/

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
 
double EPS=1e-9;
int INF=1000000005;
long long INFF=1000000000000000005ll;
double PI=acos(-1);
int dirx[8]={ -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8]={ 0, 1, -1, 0, -1, 1, -1, 1 };
ll MOD = 1000000007;
 
// ll sum() { return 0; }
// template<typename T, typename... Args>
// T sum(T a, Args... args) { return a + sum(args...); }
 
#define DEBUG fprintf(stderr, "====TESTING====\n")
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
#define OUT(x) cout << x << endl
#define OUTH(x) cout << x << " "
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define READ(x) for(auto &(z):x) cin >> z;
#define FOR(a, b, c) for (int(a)=(b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a)=(b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a)=(b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a)=(b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a)=(b); (a) <= (c); ++(a))
#define EACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a=max(a, b)
#define MIN(a, b) a=min(a, b)
#define SQR(x) ((ll)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define what_is(x) cerr << #x << " is " << x << endl


void solve() {
	int n; cin >> n;
	vi a(n), freq(n);
	vii v(n, {-1, -1}); 
	REP(i, n) {
		cin >> a[i];
		a[i]--;
		freq[a[i]]++;
		// update leftmost occurrence
		if(v[a[i]].fi == -1) v[a[i]] = {i, i}; 
		// update rightmost occurence
		v[a[i]].se = i;
	}
	// dp[i] : max unmoved elements in the suffix [i, n]
	vi dp(n + 1);
	// cnt[a[i]]: number of elements with color a[i] in range [i, n]
	vi cnt(n);
	FORD(i, n - 1, 0) {
		dp[i] = dp[i + 1];
		cnt[a[i]]++;
		// leave all a[i] in [l, r] unmoved n move everything else within [l, r] to the end
		if(i == v[a[i]].fi) MAX(dp[i], dp[v[a[i]].se + 1] + freq[a[i]]);
		// keep all a[i] in [i, n] unmoved n move everything else 
		else MAX(dp[i], cnt[a[i]]);
	}
	OUT(n - dp[0]);
}
 
 
 
int main()
{
    FAST_INP;
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt","r", stdin);
//    freopen("output.txt","w", stdout);
//    #endif
 
    // int tc; cin >> tc;
    // TC(tc) solve();
    solve();
    return 0;
}