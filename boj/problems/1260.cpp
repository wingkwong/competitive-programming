/*
DFS와 BFS
https://www.acmicpc.net/problem/1260
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

vi vis;
vvi g;

void dfs(int x) {
	OUTH(x + 1);
	vis[x] = 1;
	EACH(k, g[x]) {
		if(!vis[k]) {
			dfs(k);
		}
	}
}

void bfs(int x) {
	queue<int> q;
	q.push(x);
	while(!q.empty()) {
		int k = q.front();
		q.pop();
		OUTH(k + 1);
		EACH(v, g[k]) {
			if(!vis[v]) {
				vis[v] = 1;
				q.push(v);
			}
		}
	}
}

void solve() {
	int n, m, first;
	cin >> n >> m >> first;
	--first;
	g.resize(n);
	vis.resize(n);
	vis[first] = 1;
	REP(i, m) {
		int u, v; 
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}
	// 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 
	// 더 이상 방문할 수 있는 점이 없는 경우 종료한다
	EACH(x, g) SORT(x);
	dfs(first);
	OUT("");
	vis.assign(vis.size(), 0);
	vis[first] = 1;
	bfs(first);
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
