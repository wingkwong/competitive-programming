/** 
* Time: 2021-03-18 22:50:25
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

set<vvi> S;

void go(int h, int w, int a, int b, vvi& m) {
	if(a == 0) {
		vvi m2 = m;
		// place 1 x 1
		REP(i, h) REP(j, w) if(m2[i][j] == -1) m2[i][j] = 5;
		S.insert(m2);
	} else {
		REP(i, h) REP(j, w) {
			if(i + 1 < h) {
				if(m[i][j] == -1 && m[i + 1][j] == -1) {
					// place 2 x 1 vertically
					m[i][j] = 1, m[i + 1][j] = 2;
					go(h, w, a - 1, b, m);
					// remove 2 x 1 vertically
					m[i][j] = -1, m[i + 1][j] = -1;
				}
			}
			if(j + 1 < w) {
				if(m[i][j] == -1 && m[i][j + 1] == -1) {
					// place 2 x 1 horizontally
					m[i][j] = 3, m[i][j + 1] = 4;
					go(h, w, a - 1, b, m);
					// place 2 x 1 horizontally
					m[i][j] = -1, m[i][j + 1] = -1;
				}
			}
		}
	}
}

void solve() {
	int H, W, A, B;
	cin >> H >> W >> A >> B;
	vvi M(H + 1, vi(W + 1, -1));
	go(H, W, A, B, M);
	OUT(SIZE(S));
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
