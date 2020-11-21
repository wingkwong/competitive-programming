/*
HackerEarth - Demanding Guests
https://www.hackerearth.com/practice/algorithms/dynamic-programming/state-space-reduction/practice-problems/algorithm/coutinho/
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

const int mxN = 100005;
const int mxY = 10005;
int f[mxN], cnt[mxN];
ll dp[2][mxY];
bool sieve[mxN];

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
    int ans = 1;
    while(y > 0)
    {
        if(y % 2 == 1)
            ans = mul(ans, x);
        x = mul(x, x);
        y /= 2;
    }
    return ans;
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
	int n, q; cin >> n >> q;
	FOR(i, 2, mxN) {
		if(!sieve[i]) {
			for(int j = i; j < mxN; j += i){
				f[j] = i;
				sieve[j] = true;
			}
			sieve[i] = false;
		}
	}
	REP(i, n) {
		int x; cin >> x;
		while(x > 1) {
			int p = f[x];
			cnt[p]++;
			x /= p;
		}
	}
	int prev = 0, cur = 1, sum = 0;
	dp[prev][0] = 1;
	FOR(i, 2, mxN) {
		if(sieve[i] || cnt[i] == 0) continue;
		dp[cur][0] = dp[prev][0];
		sum += cnt[i];
		ll max_pow = binpow(i, cnt[i] + 1);
		FORN(j, 1, min(mxY - 1, sum)) {
			dp[cur][j] = add(mul(dp[cur][j - 1], i), dp[prev][j]);
			if(j > cnt[i]) {
				ll k = mul(max_pow, dp[prev][j - cnt[i] - 1]);
				dp[cur][j] = (dp[cur][j] + MOD - k) % MOD;
			}
		}
		swap(cur, prev);
	}
	TC(q) {
		int x; cin >> x;
		OUT(dp[prev][x]);
	}
    return 0;
}
