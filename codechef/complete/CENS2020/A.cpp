/*
Code Ensemble (Rated for Division 2) - Priya and AND
https://www.codechef.com/CENS2020/problems/CENS20D
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


int main()  
{ 
    FAST_INP;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    #endif
    
    // int tc; cin >> tc;
    // TC(tc) solve();
    int n,m;
    cin >> n >> m;
    vector<string> g(n);
    vvi pre(n,vi(m));
    REP(i,n) cin >> g[i];
    int q;
    cin >> q;
    int x1,y1,x2,y2;
    // 2d range update
    TC(q){
        cin >> x1 >> y1 >> x2 >> y2;
        --x1,--y1,--x2,--y2;
        pre[x1][y1]++;
        if(x2+1<n&&y2+1<m) pre[x2+1][y2+1]++;
        if(x2+1<n) pre[x2+1][y1]--;
        if(y2+1<m) pre[x1][y2+1]--;
    }

    REP(i,m) FOR(j,1,n) pre[j][i]+=pre[j-1][i];
    REP(i,n) FOR(j,1,m) pre[i][j]+= pre[i][j-1];

    REP(i,n) {
        REP(j,m) {
            if(pre[i][j]&1){
                if(g[i][j]=='1') cout << 0;
                else cout << 1;
            } else cout << g[i][j];
        }
        OUT("");
    }
    return 0; 
} 