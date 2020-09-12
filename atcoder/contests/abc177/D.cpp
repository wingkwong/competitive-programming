/*
AtCoder Beginner Contest 177- D - Friends
https://atcoder.jp/contests/abc177/tasks/abc177_d
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

class DSU {
private:
    vector<ll> d, sz;
public:
    DSU(ll n) {
        d=vector<ll>(n);
        sz=vector<ll>(n, 1);
        REP(i,n) d[i]=i;
    }

    ll p(ll a) {
        if (d[a]==a) return a;
        else return d[a]=p(d[a]);
    }

    ll get_sz(ll a) {
        return sz[p(a)];
    }

    void unite(ll a, ll b) {
        ll pa=p(a);
        ll pb=p(b);
        if (pa==pb) return;
        else {
            sz[pb]+=sz[pa];
            sz[pa]=0;
            d[pa]=pb;
            return;
        }
        return;
    }
};

// Solution 1: Use custom DSU template to find out the max tree size
// AC - 55 ms
void solve() {
	ll n, m, a, b;
	cin >> n >> m;
	DSU d=DSU(n);
    REP(i,m){
    	cin >> a >> b;
    	--a,--b;
		d.unite(a,b);
	}
	int ans=-INT_MAX;
	REP(i,n) MAX(ans,(int)d.get_sz(i));
	OUT(ans);
}

// Solution 2: Use BFS to find out the max length of connected components
// AC - 82 ms
void solve2(){
    ll n, m, a, b;
	cin >> n >> m;
    vvi g(n);
    vi vis(n,0);
    REP(i,m){
    	cin >> a >> b;
    	--a,--b;
        g[a].pb(b);
        g[b].pb(a);
	}
    int ans=0, cnt;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        vis[i]=1, cnt=0;
        q.push(i);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cnt++;
            EACH(v,g[u]){
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        MAX(ans,cnt);
    }
    OUT(ans);
}

// Solution 3: Use ACL - DSU to find out the max tree size
// Similar to solution 1

#include <atcoder/dsu>
using namespace atcoder;
void solve3(){
	ll n, m, a, b;
	cin >> n >> m;
	dsu d=dsu(n);
    REP(i,m){
    	cin >> a >> b;
    	--a,--b;
		d.merge(a,b);
	}
	int ans=-INT_MAX;
	REP(i,n) MAX(ans,(int)d.size(i));
	OUT(ans);
}

int main()
{
    FAST_INP;
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt","r", stdin);
//    freopen("output.txt","w", stdout);
//    #endif
//
//    int tc; cin >> tc;
//    TC(tc) solve();

    // solve1();
    solve2(); 
//	solve3();
    return 0;
}
