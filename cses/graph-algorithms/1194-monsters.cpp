/*
Monsters
https://cses.fi/problemset/task/1194
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

const int mxN = 1e3 + 5;
vl ans;
ll vis[mxN];

void solve() {
  // bfs all Ms & A to see if there is a path reach the boundary without crossing M
  // Example: 

  // 4 4
  // ####
  // ..A#
  // #.##
  // #M##

  // # # # # 
  // . . A # 
  // # M # # 
  // # M # # 

  // # # # # 
  // . A A # 
  // # M # # 
  // # M # # 

  // # # # # 
  // . A A # 
  // # M # # 
  // # M # # 

  // # # # # 
  // A A A # 
  // # M # # 
  // # M # # 

  int n, m;
  int ax, ay; // coordinates of A
  int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
  cin >> n >> m;
  queue<pii> q;
  vector<vector<char>> g(n, vector<char>(m));
  vvi par(n, vi(m));
  REP(i, n) {
    REP(j, m) {
      cin >> g[i][j];
      if(g[i][j] == 'M') q.push({i, j});
      if(g[i][j] == 'A') ax = i, ay = j;
    }
  }
  par[ax][ay] = -1;
  q.push({ax, ay});

  while(!q.empty()) {
    pii p = q.front();
    q.pop();
    int x = p.fi, y = p.se;
    if(
        // check if it reaches one of the boundary squares
        (x == 0 || y == 0 || x == n - 1 || y == m - 1) &&
        // check if it is u reaching one of the boundary squares, not the monsters 
        (g[x][y] == 'A')
      ) 
    {
      OUT("YES");
      string ans;
      int prev = par[x][y];
      // bracktrack the ans
      while(prev != -1) {
        x -= dx[prev], y -= dy[prev];
        ans += "DLUR"[prev];
        prev = par[x][y];
      }
      REVERSE(ans);
      OUT(SIZE(ans));
      OUT(ans);
      return;
    }
    // traverse 4 directions
    for(int d = 0; d < 4; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if(nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny] == '.') {
        g[nx][ny] = g[x][y];
        // store the prev move for backtracking later
        if(g[nx][ny] == 'A') par[nx][ny] = d;
        q.push({nx, ny});
      }
    }
  }
  OUT("NO");
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

