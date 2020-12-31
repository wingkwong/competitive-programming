/*
Good Bye 2020 - E. Apollo versus Pan
https://codeforces.com/contest/1466/problem/E
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

const int mxP = 60, mxN = 5e5 + 5;
ll cnt[mxP], x[mxN];

void solve() {
	ll n; cin >> n;
	//  n Σ (i = 1) n Σ (j = 1) n Σ (k = 1) (x[i] & x[j]) * (x[j] | x[k])
	// 	= n Σ (j = 1) n Σ (i = 1) (x[i] & x[j]) n Σ (k = 1) (x[j] | x[k])
	// 	= n Σ (j = 1) [ n Σ (i = 1) (x[i] & x[j]) ] * [ n Σ (k = 1) (x[j] | x[k]) ]
	// 	------------------------------------------------------------------------------------
	// 	let f(x, c) be the value of c-th bit in x
	// 	n Σ (i = 1) (x[i] & x[j])
	//	= 60 Σ (c = 0) 2 ^ c n Σ (i = 1) f(x[i], c) * f(x[j], c) as 0 <= x[i] <= 2 ^ 60
	//  = 60 Σ (c = 0) 2 ^ c f(x[j], c) n Σ (i = 1) f(x[i], c)
	//
	//  n Σ (k = 1) (x[j] | x[k])
	// 	= 60 Σ (c = 0) 2 ^ c [ n - (1 - f(x[j], c)) n Σ (i = 1) 1 - f(x[i], c) ]
	// 	ans = n Σ (j = 1) [ 60 Σ (c = 0) 2 ^ c f(x[j], c) n Σ (i = 1) f(x[i], c) ] *
	// 					  [ 60 Σ (c = 0) 2 ^ c [ n - (1 - f(x[j], c)) n Σ (i = 1) 1 - f(x[i], c) ] ]
	memset(cnt, 0, sizeof(cnt));
	FORN(i, 1, n) {
		cin >> x[i];
		REP(j, mxP) cnt[j] += x[i] >> j & 1;
	}
	ll ans = 0;
	FORN(i, 1, n) {
		ll val_or = 0, val_and = 0;
		REP(j, mxP) {
			if(x[i] >> j & 1) {
				val_or += (1LL << j) % MOD * n;
				val_and += (1LL << j) % MOD * cnt[j];
			} else {
				val_or += (1LL << j) % MOD * cnt[j];
			}
		}
		val_or %= MOD, val_and %= MOD;
		ans = (ans + 1LL * val_or * val_and) % MOD;
	}
	OUT(ans);
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
