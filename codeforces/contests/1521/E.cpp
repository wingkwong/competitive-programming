#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

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

template<typename T_vector>
void output_vector(const T_vector &v, bool line_break = false, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
    for (int i = start; i < end; i++) {
      cout << v[i] + (add_one ? 1 : 0) << (line_break ? '\n' : i < end - 1 ? ' ' : '\n');
    }
}

void solve() {
    int sum, k; cin >> sum >> k;
    vii a(k);
    REP(i, k) {
        cin >> a[i].fi;
        a[i].se = i + 1;
    }
    SORT(a);
    REVERSE(a);
    int mx_count = a[0].fi;
    int l = 0, r = 1e5;
    auto ok = [&](int size) {
        // mx <= n * ceil(n / 2)
        int ok1 = mx_count > size * (long long)((size + 1) / 2);
        // m <= n ^ 2 - floor(n / 2) ^ 2
        int ok2 = sum > size * (long long)size - (size / 2) * (long long)(size / 2);
        return !ok1 && !ok2;
    };
    // binary search the grid size n
    while(r - l > 1) {
        int m = l + (r - l) / 2;
        if(ok(m)) r = m;
        else l = m;
    }
    int n = r;
    OUT(n);
    vii order;
    // type 1 - bottom left
    REP(i, n) REP(j, n) {
        if(i % 2 == 1 && j % 2 == 0) {
            order.pb({i, j});
        }
    }
    // type 2 - top left
    REP(i, n) REP(j, n) {
        if(i % 2 == 0 && j % 2 == 0) {
            order.pb({i, j});
        }
    }
    // type 3 - top right
    REP(i, n) REP(j, n) {
        if(i % 2 == 0 && j % 2 == 1) {
            order.pb({i, j});
        }
    }
    int cur = 0;
    vvi ans(n, vi(n, 0));
    EACH(x, a) {
        // x.fi : count
        // x.se : value
        REP(i, x.fi) {
            ans[order[cur].fi][order[cur].se] = x.se;
            cur++;
        }
    }
     REP(i, n) {
        REP(j, n) {
            OUTH(ans[i][j]);
        }
        OUT("");
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
    // solve();
    return 0;
}
