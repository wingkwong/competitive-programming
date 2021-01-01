/*
Range Updates and Sums
https://cses.fi/problemset/task/1735
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
#define what_is(x) cerr << #x << " is " << x << endl;


// SEGMENTTREE with lazy propagation starts
struct node {
  ll sum;
  ll setAll;
  ll increment;
  bool setAllValid;
  node() {
    sum = 0;
    setAllValid = 0;
    increment = 0;
  }
  void Reset() { setAllValid = increment = 0; }
};

class segtree {
  int range;
  vector<node> tree;

 public:
  void build(vector<int>& v) {
    range = v.size();
    tree.assign(4 * range, node());
    build_recur(v, 0, range - 1, 0);
  }
  void build_recur(vector<int>& v, int l, int r, int node_no) {
    if (l == r) {
      if (l < v.size())
        tree[node_no].sum = v[l];
      else
        tree[node_no].sum = 0;
      return;
    }
    int mid = (l + r) / 2;
    build_recur(v, l, mid, 2 * node_no + 1);
    build_recur(v, mid + 1, r, 2 * node_no + 2);
    tree[node_no].sum = tree[2 * node_no + 1].sum + tree[2 * node_no + 2].sum;
  }
  ll range_query(int L, int R) {
    return range_query_recur(0, 0, range - 1, L, R);
  }

  void incUpdate_recur(int node, int l, int r, int& L, int& R, int& X) {
    if (r < L || R < l || l >= range) return;
    if (L <= l && R >= r) {
      tree[node].increment += X;
      return;
    }
    applyAggr(node, l, r);
    int mid = (l + r) / 2;
    incUpdate_recur(2 * node + 1, l, mid, L, R, X);
    incUpdate_recur(2 * node + 2, mid + 1, r, L, R, X);
    applyAggr(2 * node + 1, l, mid);
    applyAggr(2 * node + 2, mid + 1, r);
    tree[node].sum = tree[2 * node + 1].sum + tree[2 * node + 2].sum;
  }

  void incUpdate(int L, int R, int X) {
    incUpdate_recur(0, 0, range - 1, L, R, X);
  }

  void setUpdate_recur(int node, int l, int r, int& L, int& R, int& X) {
    if (r < L || R < l || l >= range) return;
    if (L <= l && R >= r) {
      tree[node].setAllValid = 1;
      tree[node].setAll = X;
      tree[node].increment = 0;
      return;
    }
    applyAggr(node, l, r);
    int mid = (l + r) / 2;
    setUpdate_recur(2 * node + 1, l, mid, L, R, X);
    setUpdate_recur(2 * node + 2, mid + 1, r, L, R, X);
    applyAggr(2 * node + 1, l, mid);
    applyAggr(2 * node + 2, mid + 1, r);
    tree[node].sum = tree[2 * node + 1].sum + tree[2 * node + 2].sum;
  }

  void setUpdate(int L, int R, int X) {
    setUpdate_recur(0, 0, range - 1, L, R, X);
  }

  void compose(int par, int child) {
    if (tree[par].setAllValid) {
      tree[child].setAllValid = 1;
      tree[child].setAll = tree[par].setAll;
      tree[child].increment = tree[par].increment;
    } else
      tree[child].increment += tree[par].increment;
  }

  void applyAggr(int node, int l, int r) {
    if (tree[node].setAllValid)
      tree[node].sum = (r - l + 1) * tree[node].setAll;

    tree[node].sum += (r - l + 1) * tree[node].increment;

    if (l != r) {
      compose(node, 2 * node + 1);
      compose(node, 2 * node + 2);
    }

    tree[node].Reset();
  }

  ll range_query_recur(int node, int l, int r, int& L, int& R) {
    if (r < L || R < l || l >= range) return 0;
    applyAggr(node, l, r);
    if (L <= l && R >= r) return tree[node].sum;
    int mid = (l + r) / 2;
    return range_query_recur(2 * node + 1, l, mid, L, R) +
           range_query_recur(2 * node + 2, mid + 1, r, L, R);
  }
};
// SEGMENTTREE with lazy propagation ends

void solve() {
	ll n, q; 
	cin >> n >> q;

	vi x(n);
	READ(x);
  segtree sg;
  sg.build(x);

	TC(q) {
		ll t, a, b, x;
		cin >> t;
		if(t == 1) {
      // Increase each value in range [a,b] by x
      cin >> a >> b >> x;
      --a, --b;
      sg.incUpdate(a, b, x);
    } else if(t == 2) {
      // Set each value in range [a,b] to x
      cin >> a >> b >> x;
      --a, --b;
      sg.setUpdate(a, b, x);
    } else {
      // Calculate the sum of values in range [a,b]
      cin >> a >> b;
      --a, --b;
      OUT(sg.range_query(a, b));
    }
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
