/*
Word Combinations
https://cses.fi/problemset/task/1731
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


// trie snippet starts
const int mxN = 1000005;
int stop[mxN], trie[27][mxN];
bool created[mxN];
int sz = 0;
// dp[i] : number of ways to form the string s[i : n] where n is the size of s using the given words
int dp[mxN];

void insert(string &s) {
  int v = 0;
  for (int i = 0; i < s.size(); i++) {
    int c = s[i] - 'a';
    if (!created[trie[c][v]]) {
      trie[c][v] = ++sz;
      created[sz] = 1;
    }
    v = trie[c][v];
  }
  ++stop[v];
}

// bool search(string tmp) {
//   int v = 0;
//   for (int i = 0; i < tmp.size(); i++) {
//     int c = tmp[i] - 'a';
//     if (!created[trie[c][v]]) return false;
//     v = trie[c][v];
//   }
//   return stop[v];
// }

int search(string s, int j) {
  int v = 0, res = 0;
  for (int i = j; i < s.size(); i++) {
    int c = s[i] - 'a';
    if (!created[trie[c][v]]) return res;
    v = trie[c][v];
    if (stop[v]) res = (res + dp[i + 1]) % MOD;
  }
  return res;
}
// trie snippet ends

void solve() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  TC(n) {
    string x;
    cin >> x;
    insert(x);
  }
  int k = SIZE(s);
  dp[k] = 1;
  FORD(i, k - 1, 0) dp[i] = search(s, i);
  OUT(dp[0]);
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
