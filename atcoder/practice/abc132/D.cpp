/*
AtCoder Beginner Contest 132 - D - Blue and Red Balls
https://atcoder.jp/contests/abc132/tasks/abc132_d
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

ll sum() { return 0; }
template<typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }

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
#define what_is(x) cerr << #x << " is " << x << endl;

// AC - 43 ms
void solve() {
	ll n, k;
	cin >> n >> k;
	vvl v(n+5,vl(n+5,0));
	v[0][0]=1;
	FORN(i,1,n){
		v[i][0]=1;
		FORN(j,1,i){
			v[i][j]=(v[i-1][j-1]+v[i-1][j])%MOD;
		}
	}
	FORN(i,1,k){
		OUT(v[n-k+1][i]*v[k-1][i-1]%MOD);
	}
}


// AC - 12 ms
void solve2(){
	struct comb{
		public:
		vector<ll> fac, finv, inv;
		comb(int mxN) {
			fac.resize(mxN);
			finv.resize(mxN);
			inv.resize(mxN);
			fac[0] = fac[1] = 1;
			finv[0] = finv[1] = 1;
			inv[1] = 1;
			for (int i = 1; i < mxN-1; i++) {
				fac[i+1] = fac[i] * (i+1) % MOD;
				inv[i+1] = MOD - inv[MOD%(i+1)]*(MOD/(i+1))%MOD;
				finv[i+1] = finv[i]*inv[i+1] % MOD;
			}
		}

		ll ncr(ll n, ll k) {
			if (k < 0 || n < k) return 0;
			ll res = 1;
			res *= fac[n]*finv[k]%MOD*finv[n-k]%MOD;
			return res;
		}

	};

	ll n, k;
	cin >> n >> k;
	comb c = comb(n);
	FORN(i,1,k){
		OUT((c.ncr(n-k+1,i)*c.ncr(k-1,i-1)%MOD));
	}
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


	/*
		the answer is c(n-k+1) * c(k-1,i-1)
		c(n-k+1): how many ways to order the R red balls and the i buckets of blue balls
		c(k-1,i-1): how many ways to distribute blue balls into i buckets
	*/


//	solve();
	solve2();
    return 0;
}
