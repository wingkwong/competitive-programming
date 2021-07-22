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
int n; cin >> n;
	vi black(n), white(n);
	int red, p, q, r, s, f = 0, j = 1, who = 0;
	READ(black); READ(white);
	SORT(black); SORT(white);
	cin >> red >> p >> q >> r >> s;
	int f1 = 0, lb = (int) black.size(), lw = (int) white.size();
	while(f == 0) {
//		OUT("====================");
//		what_is(j);
//		what_is(who);
//		what_is(lb);
//		what_is(lw);
//		OUT("====================");
		if(j == 1) {
			f1 = 0, lb = (int) black.size();
			if(lb == 0) {
				if(red <= p) who = 1, f = 1;
				else p++, f1 = 1;
			}
			FORD(i, lb - 1, 0) {
//				cout << p << " >= " << black[i] << "\n";
				if(p >= black[i]) {
					p += black[i];
					black.pop_back();
					f1 = 1;
					break;
				}
			}
			p += f1 == 0, j++;
		} else if(j == 2) {
			f1 = 0, lw = (int) white.size();
			if(lw == 0) {
				if(red <= q) who = 2, f = 1;
				else q++, f1 = 1;
			}
			FORD(i, lw - 1, 0) {
				if(q >= white[i]) {
					q += white[i];
					white.pop_back();
					f1 = 1;
					break;
				}
			}
			q += f1 == 0, j++;
		} else if(j == 3) {
			f1 = 0, lb = (int) black.size();
			if(lb == 0) {
				if(red <= r) who = 1, f = 1;
				else r++, f1 = 1;
			}
			FORD(i, lb - 1, 0) {
				if(r >= black[i]) {
					r += black[i];
					black.pop_back();
					f1 = 1;
					break;
				}
			}
			r += f1 == 0, j++;
		} else if(j == 4) {
			f1 = 0, lw = (int) white.size();
			if(lw == 0) {
				if(red <= s) who = 2, f = 1;
				else s++, f1 = 1;
			}
			FORD(i, lw - 1, 0) {
				if(s >= white[i]) {
//					cout << s << " >= " << white[i] << "\n";
					s += white[i];
					white.pop_back();
					f1 = 1;
					break;
				}
			}
			s += f1 == 0, j = 1;
		}
	}

	if(who == 1) OUT("A-C");
	else OUT("B-D");
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
	solve();
    return 0;
}
