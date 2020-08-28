/*
Volume 3 - 1313. Some Words about Sport
https://acm.timus.ru/problem.aspx?space=1&num=2023
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

void solve(){
    int n;
    cin >> n;
    vvi c(n,vi(n));
    REP(i,n) REP(j,n) cin >> c[i][j];
    REP(i,n) for(int j=i,k=0;j>=0;j--,k++) cout << c[j][k] << " ";
    FOR(i,1,n) for(int j=n-1,k=i;k<n;j--,k++) cout << c[j][k] << " ";
    cout << endl;
}

void solve2(){
    int n,x;
    cin >> n;
    vvi c(n,vi(n));
    map<int, vi> m;
    REP(i,n) REP(j,n) {
        cin >> x;
        // the same diagonal share the same i+j
        m[i+j].pb(x);
    }
    EACH(k,m){
        FORD(y,k.second.size()-1,0){
            cout << k.second[y] << " ";
        }
    }
}

int main()  
{ 
    FAST_INP;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    #endif
    // both solutions work. 
    // solve();
    solve2();
    return 0; 
} 

// 0,0 0,1 0,2
// 1,0 1,1 1,2
// 2,0 2,1 2,2

// x 0 1 0 2 1 0
// y 0 0 1 0 1 2