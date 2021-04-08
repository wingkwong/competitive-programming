/** 
* Time: 2021-04-05 20:42:33
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


// =========================== SOLUTION 1 ===========================//

const int mxN = 5010;
vi g[mxN];
int reachable[mxN], vis[mxN], cnt = 0;


void dfs(int from) {
	reachable[from] = 1;
	EACH(to, g[from]) {
		if(!reachable[to]) {
			dfs(to);
		}
	}
}

void dfs2(int from) {
	vis[from] = 1, cnt++;
	EACH(to, g[from]) {
		if(!vis[to] && !reachable[to]) {
			dfs2(to);
		}
	}
}

void solve() {
	int N, M, S;
	cin >> N >> M >> S;
	--S;
	TC(M) {
		int U, V; cin >> U >> V;
		--U, --V;
		g[U].pb(V);
	}
	// mark all the reachable nodes from S
	dfs(S);
	vii v;
	REP(i, N) {
		if(!reachable[i]) {
			// not reachable from S
			// calculate how unreachable nodes from i
			cnt = 0;
			memset(vis, 0, sizeof(vis));
			dfs2(i);
			v.pb({cnt, i});
		}
	}
	SORT(v);
	REVERSE(v);
	int ans = 0;
	EACH(x, v) {
		if(!reachable[x.se]) {
			ans++;
			dfs(x.se);
		}
	}
	OUT(ans);
}


// =========================== SOLUTION 2 ===========================//
struct SCC : vector<int> {
  vector<vector<int>> comps;
  vector<int> S;

  SCC() {}
  SCC(vector<vector<int>>& G) : vector<int>((int)G.size(), -1), S((int)G.size()) {
    for(int i = 0; i < (int)G.size(); i++) if(!S[i]) dfs(G, i);
  }

  int dfs(vector<vector<int>>& G, int v) {
    int low = S[v] = (int)S.size();
    S.push_back(v);
    for(auto e : G[v]) if(at(e) < 0) low = min(low, S[e] ?: dfs(G, e));
    if(low == S[v]) {
      comps.push_back({});
      for(int i = S[v]; i < (int)S.size(); i++) {
        at(S[i]) = (int)comps.size() - 1;
        comps.back().push_back(S[i]);
      }
      S.resize(S[v]);
    }
    return low;
  }
};

void solve2() {
	int N, M, S;
	cin >> N >> M >> S;
	--S;
	vvi G(N);
	TC(M) {
		int U, V; cin >> U >> V;
		--U, --V;
		G[U].pb(V);
	}
	SCC scc(G);
	vi in(SIZE(scc.comps));
	REP(i, N) {
		EACH(j, G[i]) {
			if(scc[i] != scc[j]) {
                in[scc[j]]++;
            }
		}
	}
	int ans = 0;
	OUT("");
	REP(i, SIZE(scc.comps)) ans += (i != scc[S] && in[i] == 0);
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
    solve2();
    return 0;
}
