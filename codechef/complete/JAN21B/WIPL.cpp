/*
January Challenge 2021 Division 2 - Watching CPL
https://www.codechef.com/JAN21B/problems/WIPL
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

const int mxN = 4005;
int dp[mxN][mxN], suf[mxN];

void solve() {
	ll n, k;
	cin >> n >> k;
	vl h(n);
	READ(h);
	SORT(h);
	memset(dp, INFF, sizeof(dp));
	// suf[i]: suffix sum of last i boxes
	suf[n] = 0;
	FORD(i, n - 1, 0) suf[i] = suf[i + 1] + h[i];
	// dp[i][j] : min height >= j using last i boxes
	dp[n][0] = 0;
	FORD(i, n - 1, 0) {
		FORD(j, k, 0) {
			if(j <= h[i]) {
				dp[i][j] = h[i];
				continue;
			}
			if(dp[i + 1][j - h[i]] == INFF) dp[i][j] = INFF;
			else dp[i][j] = min<ll>(dp[i + 1][j], dp[i + 1][j - h[i]] + h[i]);
		}
	}
	FORD(i, n - 1, 0) {
		if(suf[i] - dp[i][k] >= k) {
			OUT(n - i);
			return;
		}
	}
	OUT(-1);
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
