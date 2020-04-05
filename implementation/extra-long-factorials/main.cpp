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

#define DEBUG fprintf(stderr, "====TESTING====\n") 
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl 
#define debug(...) fprintf(stderr, __VA_ARGS__) 
#define FOR(a, b, c) for (int(a)=(b); (a) < (c); ++(a)) 
#define FORN(a, b, c) for (int(a)=(b); (a) <= (c); ++(a)) 
#define FORD(a, b, c) for (int(a)=(b); (a) >= (c); --(a)) 
#define FORSQ(a, b, c) for (int(a)=(b); (a) * (a) <= (c); ++(a)) 
#define FORC(a, b, c) for (char(a)=(b); (a) <= (c); ++(a)) 
#define FOREACH(a, b) for (auto&(a) : (b)) 
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

int n,a[200],s=1,c,p;

int main()  
{ 
    FAST_INP;
    cin >> n;
    a[0]=1;
    FORN(i,2,n){
        c=0;
        REP(j,s){
            p=a[j]*i+c;
            a[j]=p%10;
            c=p/10;
        }
        while(c){
            a[s]=c%10;
            c/=10;
            s++;
        }
    }
    FORD(k,s-1,0) cout << a[k];
    return 0; 
} 

// 5! = 5*4*3*2*1 = 120
// 2*3*4*5 

// 5
// Looping i=2
// --------------------
// Looping j=0 s=1
// r[j]=1 i=2 c=0
// p=2
// r[j]=2
// c=0
// Looping i=3
// --------------------
// Looping j=0 s=1
// r[j]=2 i=3 c=0
// p=6
// r[j]=6
// c=0
// Looping i=4
// --------------------
// Looping j=0 s=1
// r[j]=6 i=4 c=0
// p=24
// r[j]=4
// c=2
// ============================
// c=2
// r[s]=2s=1
// c=0
// Looping i=5
// --------------------
// Looping j=0 s=2
// r[j]=4 i=5 c=0
// p=20
// r[j]=0
// c=2
// --------------------
// Looping j=1 s=2
// r[j]=2 i=5 c=2
// p=12
// r[j]=2
// c=1
// ============================
// c=1
// r[s]=1 s=2
// c=0