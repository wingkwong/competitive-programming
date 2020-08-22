/*
Codeforces Round #665 (Div. 2) - B. Ternary Sequence
https://codeforces.com/contest/1401/problem/B
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


void solve() {
	vi a(3), b(3);
	READ(a);
	READ(b);
	// c is either -2, 0, 2
	// 2    for a=2; b=1
	// -2   for a=1; b=2
	// 0    else cases
	// i.e. to make pair (1,0), (0,2) and (2,1) as much as possible
	int ans=0;
	int v = min(a[2],b[1]); // number of pair of (2,1) - produce 2 for each pair
	a[2]-=v, b[1]-=v;
	ans+= 2*v;
	
	v = min(a[0],b[2]); // number of pair of (0,2) - produce 0 for each pair
	a[0]-=v, b[2]-=v;
	
	v = min(a[1],b[0]); // number of pair of (1,0) - produce 0 for each pair
	a[1]-=v, b[0]-=v;
	
	v = min(a[1],b[2]); // number of pair (1,2) - produce -2 for each pair
	ans-= 2*v;	
	OUT(ans);
}

int main()  
{ 
    FAST_INP;
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt","r", stdin);
//    freopen("output.txt","w", stdout);
//    #endif
    
    int tc; cin >> tc;
    TC(tc) solve();

    return 0; 
} 
