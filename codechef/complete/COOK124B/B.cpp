/*
CodeChef - November Cook-Off 2020 Division 2 - Flip the String
https://www.codechef.com/COOK124B/problems/FLIP
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

void solve() {
	string a, b;
	cin >> a >> b;
	int n = (int) a.size();
	vi odd, even;
	REP(i, n) {
		if(a[i] != b[i]) {
			if(i & 1) odd.pb(i);
			else even.pb(i);
		}
	}
	int ans = 0, oddN = (int)odd.size(), evenN = (int)even.size();
	int f1 = 0, f2 = 0;
	REP(i, oddN) {
		if(i == oddN - 1) ans++;
		else if(i < oddN && odd[i + 1] - odd[i] == 2) {
			f1 = 1;
			continue;
		} else {
			if(f1) ans++, f1 = 0;
			else ans++;
		}
	}
	REP(i, evenN) {
		if(i == evenN - 1) ans++;
		else if(i < evenN - 1 && even[i + 1] - even[i] == 2) {
			f2 = 1;
			continue;
		} else {
			if(f2) ans++, f2 = 0; 
			else ans++;
		}
	}
	OUT(ans);
}

//100001
//110111
//-x-xx-

//1110101010
//1010111000
//-x---x--x-

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
