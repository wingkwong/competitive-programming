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


//ll roundDown(ll n, ll m) {
//    return n>=0?(n/m)*m:((n-m+1)/m)*m;
//}
//
//ll roundUp(ll n, ll m) {
//    return n>=0?((n+m-1)/m)*m:(n/m)*m;
//}

ll lcm(ll a, ll b){
	return (a*b)/__gcd(a,b);
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
	ll a,b,c,d;
	cin >> a >> b >> c >> d;
	// last + first - both + neither
//	ll x1 = b-a+1;
//	ll x2 = ((roundDown(b,c)-roundUp(a,c))/c)*(roundDown(b,c)==0?0:1)*(roundUp(a,c)==0?0:1)+1;
//	ll x3 = ((roundDown(b,d)-roundUp(a,d))/d)*(roundDown(b,d)==0?0:1)*(roundUp(a,d)==0?0:1)+1;
//	ll x4 = ((roundDown(b,c*d)-roundUp(a,c*d))/c*d)*(roundDown(b,c*d)==0?0:1)*(roundUp(a,c*d)==0?0:1)+1;
//	cout << roundDown(b,c) << " " <<roundUp(a,c) << endl;
//	cout << roundDown(b,d) << " " <<roundUp(a,d) << endl;
//	cout << roundDown(b,c*d) << " " <<roundUp(a,c*d) << endl;
//	cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl;
	ll e = lcm(c,d);
	ll x1 = b-a+1;        // total range (inclusive)
	ll x2 = b/c-(a-1)/c;  // disvisble by C, not D
	ll x3 = b/d-(a-1)/d;  // divisible by D, not C
	ll x4 = b/e-(a-1)/e;  // disvisble by C & D
	OUT(x1-x2-x3+x4);
    return 0;
}
