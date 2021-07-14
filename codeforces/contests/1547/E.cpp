#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

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

#define DEBUG fprintf(stderr, "====TESTING====\n")
#define VALUE(x) cerr << "The value of " << #x << " is " << x << '\n'
#define OUT(x) cout << x << '\n'
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
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define what_is(x) cerr << #x << " is " << x << '\n'

// ************************DEBUG START********************************
template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); } 
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);
// ************************DEBUG END**********************************

const int MOD = 1000000007;

template<typename T_vector>
void output_vector(const T_vector &v, bool line_break = false, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
    for (int i = start; i < end; i++) {
      cout << v[i] + (add_one ? 1 : 0) << (line_break ? '\n' : i < end - 1 ? ' ' : '\n');
    }
}

void solve() {
    int n, k; cin >> n >> k;
    vl a(k), t(k);
    READ(a);
    READ(t);
    vl c(n, INT_MAX);
    REP(i, k) c[a[i] - 1] = t[i];
    vl l(n, INT_MAX), r(n, INT_MAX);
    ll x = INT_MAX;
    REP(i, n) {
        x = min(x + 1, c[i]);
        l[i] = x;
    }
    x = INT_MAX;
    FORD(i, n - 1, 0) {
        x = min(x + 1, c[i]);
        r[i] = x;
    }
    REP(i, n) cout << min(l[i], r[i]) << " \n"[i == n - 1];
}
 
int main() {
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