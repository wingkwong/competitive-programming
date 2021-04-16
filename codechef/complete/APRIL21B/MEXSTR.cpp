/** 
* Time: 2021-04-10 12:47:39
**/

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
ll MOD = 1000000007;

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

// Partial AC
// ---------------------

// bool ok(string s, string t) {
//   ll n = SIZE(s), m = SIZE(t), i = 0, j = 0;
//   while(i < n && j < m) {
//     if(s[i] == t[j]) i++;
//     j++;
//   }
//   return i == n;
// }

// string int_to_bin(ll n) {
//   if(n == 0) return "0";
//   if(n == 1) return "1";
//   return int_to_bin(n / 2) + (n % 2 ? "1" : "0");
// };

// void solve() {
//   string S; cin >> S;
//   ll N = pow(2, SIZE(S)), ans = 0;
//   REP(i, N) {
//     if(!ok(int_to_bin(i), S)) {
//       ans = i;
//       break;
//     }
//   }
//   OUT(int_to_bin(ans));
// }

const int mxN = 1000005;
int dp1[mxN + 2], dp2[mxN + 2], zero[mxN + 2], one[mxN + 2];

void solve() {
  string S, ans = "1"; cin >> S;
  int n = SIZE(S), pos = -1;
  REP(i, n) {
    if(S[i] == '0') {
      FORN(j, pos + 1, i) zero[j] = i;
      pos = i;
    }
  }
  FOR(i, pos + 1, n) zero[i] = n;
  if(zero[0] == n) {
    OUT(0);
    return;
  }
  pos = -1;
  REP(i, n) {
    if(S[i] == '1') {
      FORN(j, pos + 1, i) one[j] = i;
      pos = i;
    }
  }
  FOR(i, pos + 1, n) one[i] = n;
  dp1[n] = dp1[n + 1] = 0, dp2[n] = dp2[n + 1] = 0;
  FORD(i, n - 1, 0) {
    dp1[i] = dp1[i + 1];
    if(S[i] == '0' && one[i] < n) MAX(dp1[i], dp1[one[i] + 1] + 1);
    if(S[i] == '1' && zero[i] < n) MAX(dp1[i], dp1[zero[i] + 1] + 1);
    dp2[i] = dp2[i + 1];
    if(one[i] < n) MAX(dp2[i], dp1[one[i] + 1] + 1);
  }
  int cur_index = one[0] + 1;
  FOR(i, 1, dp2[0] + 1) {
    if(cur_index >= n) ans.push_back('0');
    else if(zero[cur_index] >= n)  ans.push_back('0'), cur_index = zero[cur_index] + 1;
    else if(dp1[zero[cur_index] + 1] < dp2[0] - i) ans.push_back('0'), cur_index = zero[cur_index] + 1;
    else ans.push_back('1'), cur_index = one[cur_index] + 1;
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
 
    int tc; cin >> tc;
    TC(tc) solve();
    // solve();
    return 0;
}