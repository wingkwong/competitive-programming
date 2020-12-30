/*
Longest Palindrome
https://cses.fi/problemset/task/1111
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
#define what_is(x) cerr << #x << " is " << x << endl

// ------------------
// RUNTIME ERROR
// ------------------
// void solve() {
//   // dp approach - O(n ^ 2)
//   string s; cin >> s;
//   int n = SIZE(s);
//   // dp[i][j] 
//   //  = true if i == j
//   //  = s[i] == s[j] if i + 1 == j
//   //  = dp[i + 1][j - 1] && s[i] == s[j] if i + 1 <= j
//   // - true  : if s[i]..s[j] is a palindrome
//   // - false : otherwise
//    vvi dp(n, vi(n, 0));
//    string ans;
//    int start = 0, len = 1;
//    // a single char is a palindrome
//    REP(i, n) dp[i][i] = 1;
//    FORD(i, n - 1, 0) {
//     FOR(j, i + 1, n) {
//       if(s[i] == s[j]) {
//         if(i + 1 == j || dp[i + 1][j - 1]) {
//           dp[i][j] = 1;
//           if(len < j - i + 1) {
//             start = i;
//             len = j - i + 1;
//           }
//         }
//       }
//     }
//    }
//    OUT(s.substr(start, len));
// }

string manacher(string s) {
  int n = (int) s.size();
  // d1[i]: the number of palindromes accordingly with odd lengths with centers in the position i.
  // d2[i]: the number of palindromes accordingly with even lengths with centers in the position i. 
  vector<int> d1(n), d2(n);
  int l1 = 0, r1 = -1, l2 = 0, r2 = -1, mx_len = 0, start = 0;
  for (int i = 0; i < n; i++) {
      // ----------------------
      // calculate d1[i]
      // ----------------------
      int k = (i > r1) ? 1 : min(d1[l1 + r1 - i], r1 - i + 1);
      while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
      d1[i] = k--;
      if (i + k > r1) l1 = i - k, r1 = i + k;
      if(d1[i] * 2 > mx_len) start = i - k, mx_len = d1[i] * 2 - 1;
      // ----------------------
      // calculate d2[i] 
      // ----------------------
      k = (i > r2) ? 0 : min(d2[l2 + r2 - i + 1], r2 - i + 1);
      while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
      d2[i] = k--;
      if (i + k > r2) l2 = i - k - 1, r2 = i + k;
      if(d2[i] * 2 > mx_len) start = i - k - 1, mx_len = d2[i] * 2;
  }
  // return the longest palindrome
  return s.substr(start, mx_len);
}

void solve() {
    string s; cin >> s;
    // Using Manacher's algorithm 
    string ans = manacher(s);
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
