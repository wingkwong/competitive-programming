/*
AtCoder Beginner Contest 181 - D - Hachi
https://atcoder.jp/contests/abc181/tasks/abc181_d
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

bool solve(string s, int n) {
	// case 1: n < 3
	if(n < 3) {
		if(stoi(s) % 8 == 0) return true;
		REVERSE(s);
		if(stoi(s) % 8 == 0) return true;
		return false;
	}
	// case 2: n >= 3
	int cnt[10] = { 0 };
	// store the freq of each digit in s
	REP(i, n) cnt[s[i] - '0']++;
	// try all 3-digit numbers that can be divided by 8
	for (int i = 104; i < 1000; i += 8) {
        int d = i, freq[10] = { 0 };
        freq[d % 10]++, d /= 10; // digit 1
        freq[d % 10]++, d /= 10; // digit 2
        freq[d % 10]++, d = i;   // digit 3
        // if cnt[digit1] >= freq[digit1] &&
        // cnt[digit2] >= freq[digit2] &&
        // cnt[digit3] >= freq[digit3]
        // then the answer is found
        if (freq[d % 10] > cnt[d % 10]) continue;
        d /= 10;
        if (freq[d % 10] > cnt[d % 10]) continue;
        d /= 10;
        if (freq[d % 10] > cnt[d % 10]) continue;
        return true;
    }
	return false;
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
	string s;
	cin >> s;
	// if the last 3 digits are divisible by 8, then return Yes
	if(solve(s, (int)s.size())) OUT("Yes");
	else OUT("No");
    return 0;
}
