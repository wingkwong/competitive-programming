/*
January Cook-Off 2021 Division 2 - Maximise Islands 
https://www.codechef.com/COOK126B/problems/MINIL
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

const int mxN = 15, mxM = 15;

void solve() {
	// build two masks and find out which one to convert with min operations
	vector<vector<char>> g1(mxN, vector<char>(mxM)), g2(mxN, vector<char>(mxM));
	REP(i, mxN) {
		REP(j, mxM) {
			if(i & 1 && j % 2 == 0) g1[i][j] = '*', g2[i][j] = '.';
			else if(i % 2 == 0 && j & 1) g1[i][j] = '*', g2[i][j] = '.';
			else g1[i][j] = '.', g2[i][j] = '*';
		}
	}
	// g1 (3 x 3)
	// *.*
	// .*.
	// *.*
	// g2 (3 x 3)
	// .*.
	// *.*
	// .*.
	int t; cin >> t;
	TC(t) {
		int n, m; cin >> n >> m;
		int d1 = 0, d2 = 0, c1 = 0, c2 = 0;
		vector<string> a(n);
		REP(i, n) cin >> a[i];
		REP(i, n) {
			REP(j, m) {
				d1 += (g1[i][j] != a[i][j]);
				d2 += (g2[i][j] != a[i][j]);
				c1 += g1[i][j] == '*';
				c2 += g2[i][j] == '*';
			}
		}
		if(c1 > c2) OUT(d1);
		else if(c1 < c2) OUT(d2);
		else OUT(min(d1, d2));
	}
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
