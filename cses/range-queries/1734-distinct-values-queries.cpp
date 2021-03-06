/*
Distinct Values Queries
https://cses.fi/problemset/task/1734
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
// const ll MOD = 1000000007;
 
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
#define what_is(x) cerr << #x << " is " << x << endl;

// ------------------------------------------------------------------------
// MO'S ALGORITHM (Classic)
// ------------------------------------------------------------------------
// const int mxN = 2e5 + 5, block_size = 666; // > N / sqrt(N) = sqrt(N)
// struct mo {
// 	int idx, left, right;
// 	void set(int i, int l, int r) {
// 		idx = i, left = l, right = r;
// 	}
// 	bool operator < (const mo &m) const {
// 		// different block - sort by block
// 		if(left / block_size != m.left / block_size) return left / block_size < m.left / block_size;
// 		// same block - sort by right value
// 		return right < m.right;
// 	}
// };

// ------------------------------------------------------------------------
// MO'S ALGORITHM with Hilbert Curve
// ------------------------------------------------------------------------
const int mxN = 2e5 + 5;

inline int64_t hilbert_order(int x, int y, int pow, int rotate) {
	if (pow == 0) return 0;
	int hpow = 1 << (pow - 1);
	int seg = (x < hpow) ? ( (y < hpow) ? 0 : 3 ) : ( (y < hpow) ? 1 : 2 );
	seg = (seg + rotate) & 3;
	const int rotate_delta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotate_delta[seg]) & 3;
	int64_t sub_square_size = int64_t(1) << (2 * pow - 2);
	int64_t ans = seg * sub_square_size, add = hilbert_order(nx, ny, pow - 1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (sub_square_size - add - 1);
	return ans;
}

struct mo {
	int idx, left, right;
	int64_t ord;
	void set(int i, int l, int r) {
		idx = i, left = l, right = r, ord = hilbert_order(l, r, 21, 0);
	}
};

inline bool operator<(const mo &a, const mo &b) {
	return a.ord < b.ord;
}

int ans, compressed;
vi freq(mxN), res(mxN), x(mxN), compress;
vector<mo> Q(mxN);
 
void add(int x) {
	if(!freq[x]) ans++;
	freq[x]++;
}
 
void remove(int x) {
	freq[x]--;
	if(!freq[x]) ans--;
}
 
void solve() {
	int n, q, a, b;
	cin >> n >> q;
	ans = 0, compressed = 1;
	map<int, int> compress;
	REPN(i, n) {
		cin >> x[i];
		// coordinate compression
		if(compress.find(x[i]) != compress.end()) x[i] = compress[x[i]];
		else compress[x[i]] = compressed, x[i] = compressed++;
		// compress.pb(x[i]);
	}
	REPN(i, q) {
		cin >> a >> b;
		Q[i].set(i, a, b);
	}
	sort(Q.begin() + 1, Q.begin() + q + 1);
	// sort(compress.begin(), compress.end());
	// compress.erase(unique(ALL(compress)), compress.end());
	// REPN(i, n) x[i] = lower_bound(ALL(compress), x[i]) - compress.begin() + 1;
	int cur_left = 0, cur_right = 0;
	REPN(i, q) {
		while(cur_left < Q[i].left) remove(x[cur_left++]);
		while(cur_left > Q[i].left) add(x[--cur_left]);
		while(cur_right < Q[i].right) add(x[++cur_right]);
		while(cur_right > Q[i].right) remove(x[cur_right--]);
		res[Q[i].idx] = ans;
	}
	REPN(i, q) OUT(res[i]);
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