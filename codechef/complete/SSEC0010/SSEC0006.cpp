/*
SSEC - Coding Contest-2  - Prime Game
https://www.codechef.com/SSCC2020/problems/SSEC0005
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
	int a, b;
	cin >> a >> b;
	int l = (a*b)/4, r = (a*b);
	// there are 168 primes from 1 to 1000
	vi prime(168);
	prime = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,\
				61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,\
				163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,\
				241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,\
				337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,\
				431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,\
				521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,\
				617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,\
				719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,\
				823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,\
				929,937,941,947,953,967,971,977,983,991,997};
	int left=-1, right=-1;
	// look for the starting index and the ending index
	REP(i,prime.size()){
		if(left==-1&&prime[i]>=a) left=i;
		if(prime[i]<=b) right=i;
		if(prime[i]>b) break;
	}
	// brute force all the answers
	FORN(i,left,right-1){
		FORN(j,i+1,right){
			int p = prime[i]*prime[j];
			if(p>r) break;
			if(l<=p&&p<=r) {
//				cout << l << " " << p << " " << r << "\n";
				OUT((to_string(prime[i])+","+to_string(prime[j])));
			}
		}
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
	solve();
    return 0;
}
