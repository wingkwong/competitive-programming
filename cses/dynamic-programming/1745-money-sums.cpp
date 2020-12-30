/*
Money Sums
https://cses.fi/problemset/task/1745
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

// ------------------
// AC
// ------------------
// void solve() {
//   int n; cin >> n;
//   vi x(n);
//   int mx_sum = 0;
//   REP(i, n) {
//     cin >> x[i];
//     mx_sum += x[i];
//   }
//   // dp[i][j] = 
//   // 1 : possible to make sum j using first i coins 
//   // 0 : otherwise
//   vvi dp(n + 1, vi(mx_sum + 1, 0));
//   dp[0][0] = 1;
//   FORN(i, 1, n) {
//     FORN(j, 0, mx_sum) {
//       // case 1 : make sum j using the first i - 1 coins
//       dp[i][j] = dp[i - 1][j];
//       // case 2: make sum j - x[i - 1] using the first i - 1 coins
//       int sum = j - x[i - 1];
//       if(sum >= 0 && dp[i - 1][sum]) {
//         dp[i][j] = 1;
//       }
//     }
//   }
//   vi ans;
//   FORN(j, 1, mx_sum) {
//     if(dp[n][j]) ans.pb(j);
//   }
//   OUT(SIZE(ans));
//   EACH(v, ans) OUTH(v);
//   OUT("");
// }

// Optimized Solution
void solve() {
  int n; cin >> n;
  vi x(n);
  int mx_sum = 0;
  REP(i, n) {
    cin >> x[i];
    mx_sum += x[i];
  }
  // dp[i] = 
  // 1 : possible to make sum i using the given coins 
  // 0 : otherwise
  vi dp(mx_sum + 1, 0);
  dp[0] = 1;
  REP(i, n) {
    FORD(j, mx_sum, x[i]) {
      dp[j] = dp[j] | dp[j - x[i]];
    }
  }
  vi ans;
  FORN(i, 1, mx_sum) {
    if(dp[i]) ans.pb(i);
  }
  OUT(SIZE(ans));
  EACH(v, ans) OUTH(v);
  OUT("");
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
