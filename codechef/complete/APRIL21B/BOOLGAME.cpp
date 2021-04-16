/** 
* Time: 2021-04-11 16:56:03
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

double EPS=1e-9;
int INF=1000000005;
long long INFF=1000000000000000005ll;
double PI=acos(-1);
int dirx[8]={ -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8]={ 0, 1, -1, 0, -1, 1, -1, 1 };
ll MOD = 1000000007;

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
	ll N, M, K; cin >> N >> M >> K;
	vl g(N + 1); 
	REPN(i, N) cin >> g[i];
	vector<vll> a(N + 1), dp(N + 1);
	dp[0].pb({0, 0});
	REP(i, M) {
		ll u, v, d; cin >> u >> v >> d;
		a[u].pb({i, d}); a[v].pb({i, d});
	}
	FORN(i, 1, N) {
		vll dp2;
		dp2.insert(dp2.end(), ALL(dp[i - 1]));
		ll new_score = 0, new_mask = 0;
		set<ll> s1, s2;
		FORD(j, i, 1) {
            new_score += g[j], new_mask ^= (1LL << j);
			EACH(k, a[j]) {
				ll idx = k.fi, score = k.se;
				// cout << idx << " " << score << endl;
				if(s1.count(idx)) {
					new_score += score;
					continue;
				}
				s1.insert(idx);
			}
        	if(j - 2 >= 0) {
				EACH(k, dp[j - 2]) {
					ll prev_score = k.fi, old_mask = k.se;
					// cout << "prev_score : " << prev_score << " " << " ; old_mask: " << old_mask << endl;
					dp2.pb({new_score + prev_score, new_mask ^ old_mask});
				}
			} else {
				dp2.pb({new_score, new_mask});
			}
		}
		SORT(dp2); REVERSE(dp2);
		ll j = 0, cnt = 0;
		int m = SIZE(dp2);
		while(j < m && cnt < K) {
			if(!s2.count(dp2[j].se)) {
				s2.insert(dp2[j].se);
				dp[i].pb(dp2[j]); cnt++;
			}
			j++;
		}
	}
	REP(i, K) OUTH(dp[N][i].fi);
	OUT("");
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