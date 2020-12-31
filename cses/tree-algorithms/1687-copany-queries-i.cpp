/*
Company Queries I
https://cses.fi/problemset/task/1687
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

// --------------------------------
// binary lifting starts 
// --------------------------------
const int mxN = 200005;
const int mxNode = 19; // log2(mxN) + 2
vi g[mxN];
int d[mxN], up[mxN][mxNode];

void dfs(int u, int p) {
  up[u][0] = p;
  for(int i = 1; i < mxNode; i++) {
    up[u][i] = ~up[u][i - 1] ? up[up[u][i - 1]][i - 1] : -1;
  }
  for(int v : g[u]){
      if(v ^ p){
          d[v] += d[u] + 1;
          dfs(v, u);
      }
  }
}

int lift(int x, int k) {
  // find the k-th ancestor of x
  for(int i = mxNode; ~i; i--) {
    if((1 << i) & k) {
      x = up[x][i];    
    }
  }
  return x;
}
// --------------------------------
// binary lifting ends
// --------------------------------

void solve() {
  int n, q; cin >> n >> q;
  REP(i, n - 1) {
    int e; cin >> e;
    --e;
    g[e].pb(i + 1);
  }
  dfs(0, -1);
  TC(q) {
    int x, k;
    cin >> x >> k;
    --x;
    if(d[x] < k) OUT(-1);
    else OUT(lift(x, k) + 1);
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
