/*
Grid Paths
https://cses.fi/problemset/task/1625
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

int ans=0;
string s;
//vvi vis(7,vi(7,0));
int vis[7][7];

bool ok(int i, int j){
	return i>=0&&i<7&&j>=0&&j<7&&!vis[i][j];
}

void dfs(int i, int j, int k) {
	// with backtracking, a 7x7 search can produce 111712 paths
	// and : 76 billion recursive calls
	// optimization is required in this question
	if(i==6&&j==0){
		if(k==48) ans++;
		return;
	}
	vis[i][j]=1;
	if(s[k]=='?'||s[k]=='L'){
		if(j&&!vis[i][j-1]){
			// optimization:
			// avoid splitting into two parts that both contain unvisited squares
			if(!(!ok(i,j-2)&&ok(i-1,j-1)&&ok(i+1,j-1))){
				dfs(i,j-1,k+1);
			}
		}
	}
	if(s[k]=='?'||s[k]=='R'){
		if(j<6&&!vis[i][j+1]){
			// optimization:
			// avoid splitting into two parts that both contain unvisited squares
			if(!(!ok(i,j+2)&&ok(i-1,j+1)&&ok(i+1,j+1))){
				dfs(i,j+1,k+1);
			}
		}
	}
	if(s[k]=='?'||s[k]=='U'){
		if(i&&!vis[i-1][j]){
			// optimization:
			// avoid splitting into two parts that both contain unvisited squares
			if(!(!ok(i-2,j)&&ok(i-1,j-1)&&ok(i-1,j+1))) {
				dfs(i-1,j,k+1);
			}
		}
	}
	if(s[k]=='?'||s[k]=='D'){
		if(i<6&&!vis[i+1][j]){
			// optimization:
			// avoid splitting into two parts that both contain unvisited squares
			if(!(!ok(i+2,j)&&ok(i+1,j-1)&&ok(i+1,j+1))) {
				dfs(i+1,j,k+1);
			}
		}
	}
	vis[i][j]=0;
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

	cin >> s;
	dfs(0,0,0);
	OUT(ans);
    return 0;
}




