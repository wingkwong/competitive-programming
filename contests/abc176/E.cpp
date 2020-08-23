/*
AtCoder Beginner Contest 176 - E - Bomber
https://atcoder.jp/contests/abc176/tasks/abc176_e
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

int main()  
{ 
    FAST_INP;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    #endif
    
    ll H,W,M,mxR,mxC,cnt=0,cntR=0,cntC=0,ans=0;
    cin >> H >> W >> M;
    vi row(H, 0), col(W, 0), h(M), w(M);
    REP(i,M){
        cin >> h[i] >> w[i];
        --h[i], --w[i];
        // store the frequency of row and col
        row[h[i]]++, col[w[i]]++;
    }
    // find the max frequency of row and col
    mxR=*max_element(ALL(row)), mxC=*max_element(ALL(col));
    // count how many elements have such frequency for row and col
    cntR=count(ALL(row),mxR), cntC=count(ALL(col),mxC);
    // number of intersections
    cnt=cntR*cntC;
    // add mxR and mxC to ans 
    ans=mxR+mxC;
    // as stated in the question, it is possible to place the bomb at a square with a target
    // which means ans may not be the final answer as we need to substract 1 if a bomb is located in the intersection of mxR and mxC
    REP(i,M){
        if(row[h[i]]+col[w[i]]==ans){
            cnt--;
        }
    }
    OUT(ans-(cnt==0));
    return 0; 
} 

// o b o
// x o x 