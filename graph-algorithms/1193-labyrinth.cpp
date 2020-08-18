/*
Labyrinth
https://cses.fi/problemset/task/1193
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
typedef vector<pll> vll; 
typedef vector<ll> vl; 
typedef vector<vl> vvl; 

double EPS=1e-9; 
int INF=1000000005; 
ll INFF=1000000000000000005ll; 
double PI=acos(-1); 
int dirx[8]={ -1, 0, 0, 1, -1, -1, 1, 1 }; 
int diry[8]={ 0, 1, -1, 0, -1, 1, -1, 1 }; 
const ll MOD = 1000000007;

#define DEBUG fprintf(stderr, "====TESTING====\n") 
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl 
#define OUT(x) cout << x << endl 
#define debug(...) fprintf(stderr, __VA_ARGS__) 
#define READ(b) for(auto &(a):b) cin >> a;
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

struct Point{
	int x, y;
	string path;
};


// TLE on one test case. Still thinking how to solve it.
int main()  
{ 
    FAST_INP;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // #endif
    int n, m, sx, sy, dx, dy;
    cin >> n >> m;
    vector<vector<char>> g(n,vector<char>(m));
    REP(i,n) {
    	REP(j,m) {
    		cin >> g[i][j];
	    	if(g[i][j]=='A') sx=i, sy=j;
	    	if(g[i][j]=='B') dx=i, dy=j;
		}
	}
	g[sx][sy]='#';
	queue<Point> q;
	q.push({sx,sy,""});
	int row[4]={-1,0,0,1};
	int col[4]={0,-1,1,0};
	char dir[4]={'U','L','R','D'};
	function<bool(int,int)> ok = [&](int i, int j){
	  if(i<0||i>n-1||j<0||j>m-1||g[i][j]=='#') return false;
	  return true;
	};
	while(!q.empty()){
		Point p = q.front();
		q.pop();
		int xx = p.x, yy = p.y;
		string path = p.path;
		if(xx==dx&&yy==dy){
			OUT("YES");
			OUT(path.size());
			OUT(path);
			return 0;
		}
		REP(i,4){
			int x=xx+row[i], y=yy+col[i];
			if(ok(x,y)){
//				cout << x << " " << y << " : " << path+dir[i] << endl;
				g[x][y]='#';
				q.push({x,y,path+dir[i]});
			}
		}
	}
	OUT("NO");
	
    return 0; 
} 
