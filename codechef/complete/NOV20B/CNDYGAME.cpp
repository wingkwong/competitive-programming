/*
November Challenge 2020 - Magical Candy Store
https://www.codechef.com/NOV20B/problems/CNDYGAME
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

ll ans() { return 0; }
template<typename T, typename... Args>
T ans(T a, Args... args) { return a + ans(args...); }

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
#define se sevenond
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(a, sz) a, a + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(a, sz) sort(ALLA(a, sz))
#define REVERSEA(a, sz) reverse(ALLA(a, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define what_is(x) cerr << #x << " is " << x << endl;

void solve() {
	ll n; cin >> n;
	vl a(n); READ(a);
	ll q; cin >> q;
	ll last_one = -1, even = 0, odd = 0;
	vl pref(n + 1, 0), suf(n + 1, 0);
	REP(i, n){
        if (a[i] == 1) last_one = i;
        if ((a[i] & 1) ^ 1) even++, suf[i + 1] = suf[i];
		else odd++, suf[i+1] = (suf[i] % MOD + 1) % MOD;
        pref[i + 1] = (pref[i] % MOD + a[i] % MOD) % MOD;
    }
    TC(q) {
        ll r; cin >> r;
        ll c = r / n, rem = r % n, ans = 0;
        if (last_one == 0) {
            ans = (ans % MOD + c % MOD) % MOD;
            if ((rem > 1) || (rem == 1 && c == 0)) ans = (ans % MOD + 1) % MOD;
        } else if (last_one > 0 && last_one < n - 1) {
            int is_pref_odd = a[last_one - 1] & 1, is_last_odd = a[n - 1] & 1;
            ans = (ans % MOD + (((pref[n] % MOD - odd % MOD) % MOD) * c % MOD) % MOD) % MOD;
            if (is_pref_odd) ans = (ans % MOD + c % MOD) % MOD;
			else ans = (ans % MOD - c % MOD) % MOD;
			if (is_last_odd) ans = (ans % MOD + c % MOD) % MOD;
			else ans = (ans % MOD - c % MOD) % MOD;
            if (rem == 0 && is_last_odd == 0) ans = (ans % MOD + 1) % MOD;
			else if (rem != 0) {
                ans = (ans % MOD + pref[rem] % MOD - suf[rem] % MOD) % MOD;
                if (rem - 1 < last_one) {
                	if(a[rem - 1] & 1) ans = (ans % MOD + 1) % MOD;
                } else if (rem - 1 == last_one) {
                    ans = (ans % MOD + 1) % MOD;
                } else {
                    if (is_pref_odd) ans = (ans % MOD + 1) % MOD;
					else ans = (ans % MOD - 1) % MOD;
                	if(a[rem - 1] & 1) ans = (ans % MOD + 1) % MOD;
                }
            }
        } else {
            int is_last_odd = a[n - 1] & 1;
            ans = (ans % MOD + (((pref[n] % MOD - odd % MOD) % MOD) * c % MOD) % MOD) % MOD;
            if (is_last_odd) ans = (ans % MOD + c % MOD) % MOD;
			else ans = (ans - c) % MOD;
            if (rem == 0 && is_last_odd == 0) ans = (ans % MOD + 1) % MOD;
			else if (rem != 0) {
                ans = (ans % MOD + pref[rem] % MOD - suf[rem] % MOD) % MOD;
                if (a[rem - 1] & 1) ans = (ans % MOD + 1) % MOD;
            }
        }
		OUT(ans % MOD);
    }
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
