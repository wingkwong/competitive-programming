/*
Codeforces Round #684 (Div. 2) - A. Buy the String
https://codeforces.com/contest/1440/problem/A
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

// void solve() {
	// int n, c0, c1, h;
	// string s;
	// cin >> n >> c0 >> c1 >> h >> s;
// 	int cnt0 = 0, cnt1 = 0;
// 	REP(i, n) {
// 		cnt0 += s[i] == '0';
// 		cnt1 += s[i] == '1';
// 	}
// 	int ans = INT_MAX;
// 	if(cnt0 > cnt1) MIN(ans, h * cnt1 + n * c0);
// 	if(cnt1 > cnt0) MIN(ans, h * cnt0 + n * c1);
// 	MIN(ans, min(cnt0 * h + n * c1, cnt1 * h + n * c0 ));
// 	MIN(ans, cnt1 * c1 + cnt0 * c0);
// 	OUT(ans);
// }

void solve() {
	int n, c0, c1, h;
	string s;
	cin >> n >> c0 >> c1 >> h >> s;
	int n0 = 0, n1 = 0;
	EACH(c, s) {
		if(c == '0') n0++;
		else n1++;
	}
	int cost0 = min(c0, c1 + h);
	int cost1 = min(c1, c0 + h);
	OUT(cost0 * n0 + cost1 * n1);
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

    return 0;
}
