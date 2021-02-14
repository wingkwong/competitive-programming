/*
AtCoder Regular Contest 112 B - -- - B
https://atcoder.jp/contests/arc112/tasks/arc112_b
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
ll MOD = 1000000007;
 
// ll sum() { return 0; }
// template<typename T, typename... Args>
// T sum(T a, Args... args) { return a + sum(args...); }
 
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
#define what_is(x) cerr << #x << " is " << x << endl

ll go(ll a, ll b, ll c, ll d) {
    ll x = b - a + 1, y = d - c + 1;
    if(b < c || d < a) return x + y;
    if(x < y) {
    	swap(a, c); swap(b, d); swap(x, y);
    }
    if(c < a) return b - c + 1;
   	else if(b < d) return d - a + 1;
    else return b - a + 1;

}

void solve() {
	//  |--------------|		|--------------|
	// --------(-B)--------(0)--------(B)--------
	//  X 			   X        Y 	 		   Y
	// where
	// X = C - 1 / 2
	// Y = C - 2 / 2

	//  |----------------------------------------------|
	// --------------(-B)---(0)---(B)-------------------
	//  X1 	 	   Y1        			X2 	 	   	  Y2
	// 
	// (X2 - X1) + (Y2 - Y1) - MAX(0, X2 - Y2) 
	ll b, c;
	cin >> b >> c;
	if(c == 1) {
		cout << (b == 0 ? 1 : 2) << endl;
		return;
	}
	ll n = c / 2;
	// C = odd -> -B - n to -B + n
	// C = even -> B - n to B + n - 1
	if(c & 1) OUT(go(b - n, b + n - 1, -b - n, -b + n));
	else OUT(go(b - n, b + n - 1, -b - n + 1, -b + n - 1));
}
 
int main()
{
    FAST_INP;
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt","r", stdin);
//    freopen("output.txt","w", stdout);
//    #endif
 
    // int tc; cin >> tc;
    // TC(tc) solve();
    solve();
    return 0;
}