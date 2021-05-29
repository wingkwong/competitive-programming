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
#define VALUE(x) cerr << "The value of " << #x << " is " << x << '\n'
#define OUT(x) cout << x << '\n'
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
#define what_is(x) cerr << #x << " is " << x << '\n'

template<typename T_vector>
void output_vector(const T_vector &v, bool line_break = false, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
    for (int i = start; i < end; i++) {
      cout << v[i] + (add_one ? 1 : 0) << (line_break ? '\n' : i < end - 1 ? ' ' : '\n');
    }
}

// int cnt_digit(int x) {
//     int res = 0;
//     while(x > 0) {
//         res++;
//         x /= 10;
//     }
//     return res;
// }

// WA
// void solve() {
//     int x; cin >> x;
//     int m = 11;
//     if(x < m) {
//         OUT("NO");
//         return;
//     }
//     // 111111111 
//     //  11111111
//     //   1111111
//     int tmp = x;
//     vi a = {0, 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};
//     while(x > 0) {
//         int d = cnt_digit(x);
//         if(x < a[d]) d--;
//         if(d < 2) break;
//         x -= a[d];
//         int j = 0;
//         if(x > a[9]) {
//             j = 9;
//         } else {
//             FORN(i, 2, 9) {
//                 if(a[i] > x) break;
//                 j = i;
//             }
//             if(j == 0) break;
//         }
//         what_is(a[j]);
//         x -= a[j];
//     }
//     what_is(x);
//     if(x == 0) OUT("YES");
//     else OUT("NO");
// }

void solve() {
    int x; cin >> x;
    int m = 11;
    if(x < m) {
        OUT("NO");
        return;
    }
    int n = 111;
    // gcd(m, n) = 1
    // by Chicken McNugget Theorem, (m - 1) * n - m
    // ref: https://artofproblemsolving.com/wiki/index.php/Chicken_McNugget_Theorem
    int mi = (m - 1) * n - m;
    if(x > mi) {
        OUT("YES");
        return;
    }
    // 1111  = 11 * 100 + 11
    // 11111 = 111 * 100 + 11
    // x = a * 11 + b * 111
    // x = (a + 10 * b) * 11 + b
    int d = x / m;
    int r = x % m;
    if(d >= r * 10) OUT("YES");
    else OUT("NO");
}
 
int main() {
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