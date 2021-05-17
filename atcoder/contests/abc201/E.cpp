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
ll MOD = 1000000007;

#define DEBUG fprintf(stderr, "====TESTING====\n")
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
#define OUT(x) cout << x << "\n"
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

template<typename T_vector>
void output_vector(const T_vector &v, bool line_break = false, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
    for (int i = start; i < end; i++) {
      cout << v[i] + (add_one ? 1 : 0) << (line_break ? '\n' : i < end - 1 ? ' ' : '\n');
    }
}

const int mxN = 60;
int p[mxN];

void solve() {
    int n; cin >> n;
    // let x be root, k be LCA
    // d(i, j) = d(k, i) ^ d(k, j)
    //         = d(k, i) ^ d(k, j) ^ d(x, k) ^ d(x, k)
    //         = (d(k, i) ^ d(x, k)) ^ (d(k, j) ^ d(x, k))
    //         = d(x, i) ^ d(x, j)
    vector<vector<pll>> g(n), weight(n);
    REP(i, n - 1) {
        ll u, v, w; cin >> u >> v >> w;
        --u, --v;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    vl dist(n, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int now = q.front(); q.pop();
        EACH(x, g[now]) {
            int next = x.fi;
            ll sum = dist[now] ^ x.se;
            if(dist[next] == -1) {
                dist[next] = sum;
                q.push(next);
            }
        }
    }
    ll ans = 0;
    REP(i, mxN) {
        vi cnt(2);
        REP(j, n) cnt[dist[j] >> i & 1]++;
        ans += (1LL << i) % MOD * cnt[0] % MOD * cnt[1];
        ans %= MOD;
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
 
    // int tc; cin >> tc;
    // TC(tc) solve();
    solve();
    return 0;
}
