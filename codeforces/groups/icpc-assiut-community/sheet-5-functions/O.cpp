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

}

bool isPrime(int n) {
	if(n==1) return 0;
	if(n==2) return 1;
	if((n&1)^1) return 0;
	for(int i=3;i<=sqrt(n);i+=2){
		if(n%i==0) return 0;
	}
	return 1;
}

bool isPalindrome(int n){
	string s = to_string(n), rev = s;
	REVERSE(rev);
	return rev == s;
}

int f1(vector<int>& a){
	return *max_element(ALL(a));
}

int f2(vector<int>& a){
	return *min_element(ALL(a));
}

int f3(vector<int>& a){
	return count_if(ALL(a), isPrime);
}

int f4(vector<int>& a){
	return count_if(ALL(a), isPalindrome);
}

int f5(vector<int>& a){
	SORT(a);
	int mx = INT_MIN, ans = a[0];
	REP(i,a.size()){
		int n = a[i], cnt = 0;
		FORN(i,1,sqrt(n)){
			if(n%i==0) {
				if(n/i==i) cnt++;
				else cnt+=2;
			}
		}
		if(cnt >= mx){
			mx = cnt;
			ans = a[i];
		}
	}
	return ans;
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
	int n; cin >> n;
	vi a(n);
	READ(a);
	printf("The maximum number : %d\n", f1(a));
	printf("The minimum number : %d\n", f2(a));
	printf("The number of prime numbers : %d\n", f3(a));
	printf("The number of palindrome numbers : %d\n", f4(a));
	printf("The number that has the maximum number of divisors : %d\n", f5(a));
    return 0;
}
