/*
Investigation
https://cses.fi/problemset/task/1202
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
vector<pll> g[mxN], ans;
ll n, m, dist[mxN], mn[mxN], mx[mxN], routes[mxN];

void dijkstra() {
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.push({0, 0}); 
  memset(dist, INFF, sizeof(dist));
  memset(mn, INFF, sizeof(mn));
  dist[0] = mn[0] = mx[0] = 0; 
  routes[0] = 1;
  while (!pq.empty()) {
      pll p = pq.top(); 
      ll d = p.fi, u = p.se;
      pq.pop();
      if (d > dist[u]) continue;
      for (pll p2 : g[u]) {
          ll v = p2.fi, w = p2.se;
          if (dist[v] > dist[u] + w) {
            // reach v in a shorter distance than its current one
            dist[v] = dist[u] + w;
            routes[v] = routes[u];
            mn[v] = mn[u] + 1;
            mx[v] = mx[u] + 1;
            pq.push({dist[v], v});
          } else if (dist[v] == dist[u] + w) {
            // reach v in an equivalent distance
            (routes[v] += routes[u]) %= MOD;
            mn[v] = min(mn[v], mn[u] + 1);
            mx[v] = max(mx[v], mx[u] + 1);
          }
      }
  } 
  OUTH(dist[n - 1]);
  OUTH(routes[n - 1]);
  OUTH(mn[n - 1]);
  OUTH(mx[n - 1]);
}

void solve() {
  cin >> n >> m;
  REP(i, m) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].pb({v, w});
    // g[b].pb(a);
  }
  dijkstra();
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
