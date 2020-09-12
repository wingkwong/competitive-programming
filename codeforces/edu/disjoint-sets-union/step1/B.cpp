/*
ITMO Academy: pilot course - Disjoint Sets Union - Step 1 - B. Disjoint Sets Union 2
https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
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


// AC - 467 ms
void solve() {
	struct dsu{
	    vector <int> p, rank, mi, mx, total;

	    public:
	        dsu(int n){
	            p.resize(n + 1);
	            mi.resize(n + 1);
	            mx.resize(n + 1);
	            total.assign(n + 1, 1);
	            rank.assign(n + 1, 0);
	            init(n);
	        }

	        void init(int n){
	            for(int i = 1 ; i <= n ; ++i){
	                p[i] = mi[i] = mx[i] = i;
	            }
	        }

	        int find_parent(int element){
	            if(p[element] == element) return element;
	            return p[element] = find_parent(p[element]);
	        }

	        void union_by_rank(int a, int b){
	            int pa = find_parent(a), pb = find_parent(b);
	            if(pa == pb) return;
	            if(rank[pa] == rank[pb]) ++rank[pa];
				if(rank[pa] < rank[pb]) swap(pa,pb);
	            p[pa] = pb;
				total[pb] += total[pa];
				mi[pb] = min(mi[pa], mi[pb]);
				mx[pb] = max(mx[pa], mx[pb]);
	        }

	        int getSize(int a){
	            return total[find_parent(a)];
	        }

	        int getMin(int a){
	            return mi[find_parent(a)];
	        }

	        int getMax(int a){
	            return mx[find_parent(a)];
	        }
	};

	int n, m, u, v;
	cin >> n >> m;
	string s;
	dsu d = dsu(n);
	REP(i, m){
		cin >> s;
		if(s=="get"){
			cin >> u;
			cout << d.getMin(u) << " " << d.getMax(u) << " " << d.getSize(u) << "\n";
		} else {
			cin >> u >> v;
			d.union_by_rank(u,v);
		}
	}
}

// AC - 499 ms
void solve2(){

	struct dsu {
	  vector<int> par;
	  vector<int> mn, mx, cnt;
	  public:
	  dsu(int n){
	    par.clear(); mn.clear(), mx.clear(), cnt.clear();
	    par.resize(n), mn.resize(n), mx.resize(n), cnt.resize(n);
	    for(int i = 0; i < n; i++) {
	      par[i] = i;
	      mn[i] = mx[i] = i;
	      cnt[i] = 1;
	    }
	  }
	  int find(int x) {
	    return x == par[x] ? x : par[x] = find(par[x]);
	  }
	  bool unite(int x, int y) {
	    x = find(x);
	    y = find(y);
	    if(x != y) {
	      par[x] = y;
	      cnt[y] += cnt[x];
	      mx[y] = max(mx[y], mx[x]);
	      mn[y] = min(mn[y], mn[x]);
	      return true;
	    }
	    return false;
	  }
	};
	
	int n, m, u, v;
	cin >> n >> m;
	string s;
	dsu d = dsu(n+1);
	REP(i, m){
		cin >> s;
		if(s=="get"){
			cin >> u;
			u = d.find(u);
			cout << d.mn[u] << " " << d.mx[u] << " " << d.cnt[u] << "\n";
		} else {
			cin >> u >> v;
			d.unite(u,v);
		}
	}
}

int main()
{
    FAST_INP;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // #endif

//    int tc; cin >> tc;
//    TC(tc) solve();

//	solve();
	solve2();
    return 0;
}

