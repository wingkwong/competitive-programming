/*
AtCoder Beginner Contest 185 - F - Range Xor Query
https://atcoder.jp/contests/abc185/tasks/abc185_f
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

const int N = 3e5;
int n, m;

// segment tree - template starts
template <typename T = long long>
struct SegmentTree
{
    using F = function<T(T, T)>;
#define clz(x) __builtin_clz(x)

    SegmentTree(int n, const F f, const T &unit) : f(f), unit(unit), sz(n - 1 ? 1 << (32 - clz(n - 1)) : 1)
    {
        seg.assign(2 * sz, unit);
    }

    SegmentTree(vector<T> &a, const F f, const T &unit) : f(f), sz((int)a.size() > 1 ? 1 << (32 - clz(a.size() - 1)) : 1), unit(unit)
    {
        int n0 = a.size();
        seg.assign(2 * sz, unit);
        for (int i = 0; i < n0; ++i)
            seg[i + sz] = a[i];
        for (int i = sz - 1; i > 0; --i)
            seg[i] = f(seg[i << 1], seg[(i << 1) | 1]);
    }
    const int sz;
    vector<T> seg;
    const F f;
    const T unit;

    void set(int k, T x) { seg[k + sz] = x; }

    void build()
    {
        for (int i = sz - 1; i > 0; --i)
            seg[i] = f(seg[i << 1], seg[(i << 1) | 1]);
    }

    T query(int l, int r)
    {
        T x = unit;
        for (int d = r - l; d >= 1; d = r - l)
        {
            int L = l | ((1U << 31) >> clz(d));
            int k = __builtin_ctz(L);
            x = f(x, seg[(sz | l) >> k]);
            l += L & (-L);
        }
        return x;
    }

    void update(int i, T x)
    {
        int k = i + sz;
        seg[k] = x;
        for (k = k >> 1; k > 0; k >>= 1)
        {
            seg[k] = f(seg[k << 1], seg[(k << 1) | 1]);
        }
    }

    void add(int i, T x)
    {
        int k = i + sz;
        seg[k] += x;
        for (k = k >> 1; k > 0; k >>= 1)
        {
            seg[k] = f(seg[k << 1], seg[(k << 1) | 1]);
        }
    }
    SegmentTree() = default;
    T operator[](int k) const { return seg[sz + k]; }
};
// segment tree - templates ends


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
	vi a(n);
	READ(a);
	SegmentTree<int> seg(a, [](int x, int y) { return x ^ y; }, 0);
	REP(i, q) {
		int t, x, y;
		cin >> t >> x >> y;
		if(t == 1) seg.update(x - 1, seg[x - 1] ^ y);
		else OUT(seg.query(x - 1, y));
	}
    return 0;
}
