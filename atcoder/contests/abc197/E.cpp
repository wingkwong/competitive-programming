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

const int mxN = 2e5 + 7;
vi v[mxN];
ll l[mxN], r[mxN];

void solve() {
	int n; cin >> n;
	REP(i, n) {
		int x, c;
		cin >> x >> c;
		v[c].pb(x);
	}
	v[0].pb(0);
	v[n + 1].pb(0);
	int j = 0;
	FORN(i, 1, n + 1) {
		// no balls at coordinate i
		if(v[i].empty()) continue;
		SORT(v[i]);
		// x1 < x2 < x3 < ... < xn 
		// l                     r
		int lx = v[i].front(), rx = v[i].back(); // cur
		int ly = v[j].front(), ry = v[j].back(); // prev
		// the previous one must either end up at position v[j].front() or v[j].end()
		// find the min of (prev_head -> cur_tail , prev_tail -> cur_tail) + the length of current segement
		l[i] = min(abs(rx - ly) + l[j], abs(rx - ry) + r[j]) + rx - lx;
		// find the min of (prev_head -> cur_head , prev_tail -> cur_head) + the length of current segement
		r[i] = min(abs(lx - ly) + l[j], abs(lx - ry) + r[j]) + rx - lx;
		j = i;
	}
	cout << min(l[n + 1], r[n + 1]) << endl;
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