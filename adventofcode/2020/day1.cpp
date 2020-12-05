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

ll sum() { return 0; }
template<typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }

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
#define what_is(x) cerr << #x << " is " << x << endl;


void part1() {
  int x;
  unordered_map<int, int> m;
  while (cin >> x) {
    int t = 2020 - x;
    if (m.count(t)) {
      cout << t << " " << x << "\n";
      OUT(t * x);
      return;
    } else
      m[x] = x;
  }
}

void KSum(int k, vl &nums, int l, int r, int target, vvl &retVal, vl &cur, int ci) {
  int i, mn, mx;
  int km1 = k - 1;
  if (r - l + 1 < k) return;
  while (l < r) {
    mn = nums[l];
    mx = nums[r];
    if (mn + km1 * mx < target)
      l++;
    else if (km1 * mn + mx > target)
      r--;
    else if (k == 2) {
      cur[ci] = mn;
      cur[ci + 1] = mx;
      retVal.push_back(cur);
      l++;
      while (l < r && nums[l] == mn) l++;
      r--;
      while (l < r && nums[r] == mx) r--;
    } else {
      cur[ci] = mn;
      KSum(km1, nums, ++l, r, target - mn, retVal, cur, ci + 1);
      while (l < r && nums[l] == nums[l - 1]) l++;
    }
  }
}

void part2() {
  vl nums;
  int x;
  while (cin >> x) {
    if (x == -1) break;
    nums.pb(x);
  }
  vvl ret;
  vl v(3, 0);
  SORT(nums);
  KSum(3, nums, 0, nums.size() - 1, 2020, ret, v, 0);
  ll ans = 1;
  REP(i, 3) ans = ans * ret[0][i];
  OUT(ans);
}

int main()
{
    FAST_INP;
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt","r", stdin);
//    freopen("output.txt","w", stdout);
//    #endif

//    int tc; cin >> tc;
//    TC(tc) solve();

//	part1();
	part2();
    return 0;
}
