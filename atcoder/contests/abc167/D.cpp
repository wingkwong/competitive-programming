/*
D - Teleporter
https://atcoder.jp/contests/abc167/tasks/abc167_d
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

void solve() {
    ll n, k; 
    cin >> n >> k;
    ll a[n];
    unordered_map<ll, ll> m, d, c;
    bool duplicate = false;
    // read the input
    REP(i, n) {
        cin >> a[i];
        // store the value to map
        m[i] = a[i];
    }
    // if you take a look at the sample input 2
    // 6 727202214173249351
    // 6 5 2 5 3 2
    // you know there is no way to traverse k times
    // by listing out the travel, you should obverse the pattern 
    // to a certain point, it starts looping
    // Example:
    // 6 5 2 5 3 2
    // 1 -> 6 -> 2 -> 5 -> 3 -> 2 -> 5 -> 3 -> 2 -> 5 ....  
    // Start from the third step, it starts the loop 2 -> 5 -> 3 
    ll i = 0, step = 0, kk = k;
    while(!duplicate && kk){
        step++; // step is used to find out when a town has been visited
        if(d[i] == 1){
            // if it is visited before, that is the start of the loop
            duplicate = true;
            continue;
        }
        d[i] = 1; // set the current i to 1, in other word, this has been visited
        c[i] = step; // we need to store the step to another map because we need to calculate from where the looping starts
        i = m[i] - 1; // -1 because it s 0 based
        kk--; // monitor if it s out of boundary
    }

    // 6 5 2 5 3 2
    // 1 -> 6 -> 2 -> 5 -> 3 -> 2 -> 5 -> 3 -> 2 -> 5 ....
    //           x              x 
    // |-----------step---------|
    //           |--------------k-c[i]---------------- ....
    // |---c[i]--|                         
    // |------------------------k--------------------- ....

    // if it s not out of boundary
    if(kk){
        // the first part (k - c[i]) is the length of the repeating pattern till k
        // the second part (step - c[i]) is the length of the repeating pattern
        // the result r is how many time we need to teleport from the repeating pattern
        ll r = (k - c[i]) % (step - c[i]);
        while(r >= 0){
            i = m[i] - 1;
            r--;
        } 
    }
    OUT(i + 1);
}

// --------------------------------
// binary lifting starts 
// --------------------------------
const int mxN = 200005;
const int mxNode = 60; // ~ log2(k) 
vi g[mxN];
int up[mxN][mxNode];
 
void binary_lifting() {
  for(int i = 1; i < mxNode; i++) {
    for(int u = 0; u < mxN; u++) {
      up[u][i] = up[up[u][i - 1]][i - 1];
    }
  }
}
 
int kth_ancestor(ll u, ll k) {
  for(int i = 0; i < mxNode; i++) {
    if(k & (1LL << i)) u = up[u][i];
  }
  return u;
}
// --------------------------------
// binary lifting ends
// --------------------------------

void solve2() {
    ll n, k;
    cin >> n >> k;
    REP(i, n) {
        cin >> up[i][0];
        --up[i][0];
    }
    binary_lifting();
    OUT(kth_ancestor(0, k) + 1);
}

int main()  
{ 
    FAST_INP;
    // solve();
    solve2();
    return 0;
} 

