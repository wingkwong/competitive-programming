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

int n,a[6][6];

int main()  
{ 
    FAST_INP;
    REP(i,6){
        REP(j,6){
            cin >> a[i][j];
        }
    }

    int max=-63;

    REP(i,4){
        REP(j,4){
            int sum =   // top
                        a[i][j]+a[i][j+1]+a[i][j+2]
                        +
                        // middle
                        a[i+1][j+1]
                        +
                        // bottom
                        a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];

            if(sum>max)max=sum;
        }
    }

    cout << max;

    return 0;
}

// 1 1 1 0 0 0
// 0 1 0 0 0 0
// 1 1 1 0 0 0
// 0 0 2 4 4 0
// 0 0 0 2 0 0
// 0 0 1 2 4 0

// [0][0] [0][1] [0][2] [0][3] [0][4] [0][5]
// [1][0] [1][1] [1][2] [1][3] [1][4] [1][5]
// [2][0] [2][1] [2][2] [2][3] [2][4] [2][5]
// [3][0] [3][1] [3][2] [3][3] [3][4] [3][5]
// [4][0] [4][1] [4][2] [4][3] [4][4] [4][5]
// [5][0] [5][1] [5][2] [5][3] [5][4] [5][5] 

// 1 1 1 
//   1 
// 1 1 1 

// [0][0] [0][1] [0][2]
//        [1][1]
// [2][0] [2][1] [2][2]

// 1 1 0
// 1 0 0
// 1 1 0

// [0][1] [0][2] [0][3]
//        [1][2] 
// [2][1] [2][2] [2][3]
