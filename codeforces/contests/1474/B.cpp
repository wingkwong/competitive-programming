/*
Codeforces Round #696 (Div. 2) - B - Different Divisors
https://codeforces.com/contest/1474/problem/B
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

const int mxN = 40000;
int p[mxN], prime[mxN], k = 0;

// AC
void solve() {
	memset(p, 1, sizeof(p));
	for(int i = 2; i < mxN; i++) {
		if(p[i]) {
			prime[k++] = i;
			for(int j = i * 2; j < mxN; j += i) {
				p[j] = 0;
			}
		}
	}
	ll t; cin >> t;
	TC(t) {
		ll d; cin >> d;
		ll p = *lower_bound(prime, prime + k, d + 1);
		ll q = *lower_bound(prime, prime + k, p + d);
		cout << min(p * p * p, p * q) << endl;
	}
}

// prime_sieve starts
vector<int> prime_sieve(const int N, const int Q = 17, const int L = 1 << 15) {
    using u8 = unsigned char;
    static const int rs[] = {1, 7, 11, 13, 17, 19, 23, 29};
    struct P {
        P(int p) : p(p) {}
        int p;
        int pos[8];
    };
    auto approx_prime_count = [](const int N) -> int { return N > 60184 ? N / (log(N) - 1.1) : max(1., N / (log(N) - 1.11)) + 1; };
 
    const int v = sqrt(N), vv = sqrt(v);
    vector<bool> isp(v + 1, true);
    for(int i = 2; i <= vv; ++i)
        if(isp[i]) {
            for(int j = i * i; j <= v; j += i) isp[j] = false;
        }
 
    const int rsize = approx_prime_count(N + 30);
    vector<int> primes = {2, 3, 5};
    int psize = 3;
    primes.resize(rsize);
 
    vector<P> sprimes;
    size_t pbeg = 0;
    int prod = 1;
    for(int p = 7; p <= v; ++p) {
        if(!isp[p]) continue;
        if(p <= Q) prod *= p, ++pbeg, primes[psize++] = p;
        auto pp = P(p);
        for(int t = 0; t < 8; ++t) {
            int j = (p <= Q) ? p : p * p;
            while(j % 30 != rs[t]) j += p << 1;
            pp.pos[t] = j / 30;
        }
        sprimes.push_back(pp);
    }
 
    vector<u8> pre(prod, 0xFF);
    for(size_t pi = 0; pi < pbeg; ++pi) {
        auto pp = sprimes[pi];
        const int p = pp.p;
        for(int t = 0; t < 8; ++t) {
            const u8 m = ~(1 << t);
            for(int i = pp.pos[t]; i < prod; i += p) pre[i] &= m;
        }
    }
 
    const int block_size = (L + prod - 1) / prod * prod;
    vector<u8> block(block_size);
    u8 *pblock = block.data();
    const int M = (N + 29) / 30;
 
    for(int beg = 0; beg < M; beg += block_size, pblock -= block_size) {
        int end = min(M, beg + block_size);
        for(int i = beg; i < end; i += prod) { copy(pre.begin(), pre.end(), pblock + i); }
        if(beg == 0) pblock[0] &= 0xFE;
        for(size_t pi = pbeg; pi < sprimes.size(); ++pi) {
            auto &pp = sprimes[pi];
            const int p = pp.p;
            for(int t = 0; t < 8; ++t) {
                int i = pp.pos[t];
                const u8 m = ~(1 << t);
                for(; i < end; i += p) pblock[i] &= m;
                pp.pos[t] = i;
            }
        }
        for(int i = beg; i < end; ++i) {
            for(int m = pblock[i]; m > 0; m &= m - 1) { primes[psize++] = i * 30 + rs[__builtin_ctz(m)]; }
        }
    }
    assert(psize <= rsize);
    while(psize > 0 && primes[psize - 1] > N) --psize;
    primes.resize(psize);
    return primes;
}
// prime_sieve ends

#define lb(c, x) distance((c).begin(), lower_bound(ALL(c), (x)))

// AC
void solve2() {
	auto prime = prime_sieve(100000);
	ll t; cin >> t;
	TC(t) {
		ll d; cin >> d;
		ll ans = 1;
		ll p = prime[lb(prime, d + 1)];
		ans *= p;
		p = prime[lb(prime, p + d)];
		ans *= p;
		OUT(ans);
	}
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
    // solve();
    solve2();
    return 0;
}