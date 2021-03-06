/*
Flight Discount
https://cses.fi/problemset/task/1195
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

const int mxN = 1e5;
vector<pll> g1[mxN], g2[mxN];
vl ans;
ll vis[mxN], par[mxN], d1[mxN], d2[mxN];


// --------------------------------
// dijkstra
// Ref: https://cp-algorithms.com/graph/dijkstra_sparse.html
// --------------------------------
void dijkstra(int s, vector<pll> adj[mxN], ll d[mxN]) {
  memset(d, INFF, sizeof(d1));
  // p.assign(n, -1);
  d[s] = 0;
  priority_queue<pll, vector<pll>, greater<pll>> q;
  q.push({0, s});
  while (!q.empty()) {
      ll v = q.top().second, d_v = q.top().first;
      q.pop();
      if (d_v != d[v]) continue;
      for (auto edge : adj[v]) {
          ll to = edge.first, len = edge.second;
          if (d[v] + len < d[to]) {
              d[to] = d[v] + len;
              // p[to] = v;
              q.push({d[to], to});
          }
      }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  REP(i, m) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g1[u].pb({v, w});
    g2[v].pb({u, w});
  }
  // apply discount on the edge X where is reachable from 0 to X and N - 1 to X
  dijkstra(0, g1, d1);
  dijkstra(n - 1, g2, d2);
  ll ans = INFF;
  REP(u, n) {
    EACH(v, g1[u]) {
      MIN(ans, d1[u] + d2[v.fi] + v.se / 2);
    }
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

