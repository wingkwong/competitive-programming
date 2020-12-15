/*
AtCoder Beginner Contest 185 - E - Sequence Matching
https://atcoder.jp/contests/abc185/tasks/abc185_e
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
const ll MOD = 1000000007;

ll sum() { return 0; }
template<typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }

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
#define what_is(x) cerr << #x << " is " << x << endl;

const int mxN = 1005;
vi a, b;
int dp[mxN][mxN], n, m;

// AC - 32 ms
int go(int i, int j) {
    if (i == n || j == m) return n - i + m - j;
    if (dp[i][j] != -1) return dp[i][j];
    int ans = 1e9;
    MIN(ans, go(i + 1, j + 1) + (a[i] != b[j]));
    MIN(ans, min(go(i + 1, j), go(i, j + 1)) + 1);
    return dp[i][j] = ans;
}

// AC - 26 ms
int go2(int i, int j) {
	if(i == -1 && j == -1) return 0;
	if(i == -1) return j + 1;
	if(j == -1) return i + 1;
	if(dp[i][j] != -1) return dp[i][j];
	int x = go2(i - 1, j) + 1;
	int y = go2(i, j - 1) + 1;
	int z = go2(i - 1, j - 1) + (a[i] != b[j]);
	return dp[i][j] = min({x, y, z});
}

int main()
{
    FAST_INP;
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt","r", stdin);
//    freopen("output.txt","w", stdout);
//    #endif

//    int tc; cin >> tc;
//    TC(tc) solve();
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	memset(dp, -1, sizeof(dp));
	READ(a);
	READ(b);
//	OUT(go(0, 0));
	OUT(go2(n - 1, m - 1));
    return 0;
}
