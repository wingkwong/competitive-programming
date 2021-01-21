/*
Distinct Values Queries
https://cses.fi/problemset/task/1734
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
// const ll MOD = 1000000007;

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
#define what_is(x) cerr << #x << " is " << x << endl;

// MO'S ALGORITHM 
const int M = 2e5 + 7;
int block_size, ans, compressed;
int freq[M];
map<int, int> compress;

struct mo {
	int idx, left, right;
	void set(int i, int l, int r) {
		idx = i, left = l, right = r;
	}
	bool operator < (const mo &m) const {
		int b1 = left / block_size, b2 = m.left / block_size;
		if(b1 != b2) return b1 < b2;
		return right < m.right;
	}
};

void add(int x) {
	freq[x]++;
	if(freq[x] == 1) ans++;
}

void remove(int x) {
	freq[x]--;
	if(freq[x] == 0) ans--;
}

// TLE x 4
void solve() {
	int n, q;
	cin >> n >> q;
	vi x(n + 1), res(q);
	block_size = sqrt(n + 1);
	ans = 0, compressed = 1;
	// REPN(i, n) cin >> x[i];
	REPN(i, n) {
		cin >> x[i];
		if(compress.find(x[i]) != compress.end()) x[i] = compress[x[i]];
		else compress[x[i]] = compressed, x[i] = compressed++;
	}
	vector<mo> Q(q); 
	REP(i, q) {
		int a, b;
		cin >> a >> b;
		Q[i].set(i, a, b);
	}
	SORT(Q);
	int cur_left = 0, cur_right = 0;
	REP(i, q) {
		while(cur_right < Q[i].right) add(x[++cur_right]);
		while(cur_left > Q[i].left) add(x[--cur_left]);
		while(cur_right > Q[i].right) remove(x[cur_right--]);
		while(cur_left < Q[i].left) remove(x[cur_left++]);
		res[Q[i].idx] = ans;
	}
	REP(i, q) OUT(res[i]);
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
