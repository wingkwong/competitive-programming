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
// ll MOD = 1000000007;

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

// ModInt template starts
constexpr long long MOD = 998244353;
template <int mod>
struct ModInt {
  static int get_mod() { return mod; }
  static int get_primitive_root() {
    static int primitive_root = 0;
    if (!primitive_root) {
      primitive_root = [&]() {
        std::set<int> fac;
        int v = mod - 1;
        for (long long i = 2; i * i <= v; i++)
          while (v % i == 0) fac.insert(i), v /= i;
        if (v > 1) fac.insert(v);
        for (int g = 1; g < mod; g++) {
          bool ok = true;
          for (auto i : fac)
            if (ModInt(g).power((mod - 1) / i) == 1) {
              ok = false;
              break;
            }
          if (ok) return g;
        }
        return -1;
      }();
    }
    return primitive_root;
  }
  int val;
  constexpr ModInt() : val(0) {}
  constexpr ModInt &_setval(long long v) {
    val = (v >= mod ? v - mod : v);
    return *this;
  }
  constexpr ModInt(long long v) { _setval(v % mod + mod); }
  explicit operator bool() const { return val != 0; }
  constexpr ModInt operator+(const ModInt &x) const {
    return ModInt()._setval((long long)val + x.val);
  }
  constexpr ModInt operator-(const ModInt &x) const {
    return ModInt()._setval((long long)val - x.val + mod);
  }
  constexpr ModInt operator*(const ModInt &x) const {
    return ModInt()._setval((long long)val * x.val % mod);
  }
  constexpr ModInt operator/(const ModInt &x) const {
    return ModInt()._setval((long long)val * x.inv() % mod);
  }
  constexpr ModInt operator-() const { return ModInt()._setval(mod - val); }
  constexpr ModInt &operator+=(const ModInt &x) { return *this = *this + x; }
  constexpr ModInt &operator-=(const ModInt &x) { return *this = *this - x; }
  constexpr ModInt &operator*=(const ModInt &x) { return *this = *this * x; }
  constexpr ModInt &operator/=(const ModInt &x) { return *this = *this / x; }
  friend constexpr ModInt operator+(long long a, const ModInt &x) {
    return ModInt()._setval(a % mod + x.val);
  }
  friend constexpr ModInt operator-(long long a, const ModInt &x) {
    return ModInt()._setval(a % mod - x.val + mod);
  }
  friend constexpr ModInt operator*(long long a, const ModInt &x) {
    return ModInt()._setval(a % mod * x.val % mod);
  }
  friend constexpr ModInt operator/(long long a, const ModInt &x) {
    return ModInt()._setval(a % mod * x.inv() % mod);
  }
  constexpr bool operator==(const ModInt &x) const { return val == x.val; }
  constexpr bool operator!=(const ModInt &x) const { return val != x.val; }
  bool operator<(const ModInt &x) const {
    return val < x.val;
  }  // To use std::map<ModInt, T>
  friend std::istream &operator>>(std::istream &is, ModInt &x) {
    long long t;
    is >> t;
    x = ModInt(t);
    return is;
  }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &x) {
    os << x.val;
    return os;
  }
  constexpr long long power(long long n) const {
    long long ans = 1, tmp = this->val;
    while (n) {
      if (n & 1) ans = ans * tmp % mod;
      tmp = tmp * tmp % mod;
      n /= 2;
    }
    return ans;
  }
  constexpr long long inv() const { return this->power(mod - 2); }
  constexpr ModInt operator^(long long n) const { return ModInt(this->power(n)); }
  constexpr ModInt &operator^=(long long n) { return *this = *this ^ n; }

  inline ModInt fac() const {
    static std::vector<ModInt> facs;
    int l0 = facs.size();
    if (l0 > this->val) return facs[this->val];

    facs.resize(this->val + 1);
    for (int i = l0; i <= this->val; i++)
      facs[i] = (i == 0 ? ModInt(1) : facs[i - 1] * ModInt(i));
    return facs[this->val];
  }

  ModInt doublefac() const {
    long long k = (this->val + 1) / 2;
    if (this->val & 1)
      return ModInt(k * 2).fac() / ModInt(2).power(k) / ModInt(k).fac();
    else
      return ModInt(k).fac() * ModInt(2).power(k);
  }

  ModInt nCr(const ModInt &r) const {
    if (this->val < r.val) return ModInt(0);
    return this->fac() / ((*this - r).fac() * r.fac());
  }

  ModInt sqrt() const {
    if (val == 0) return 0;
    if (mod == 2) return val;
    if (power((mod - 1) / 2) != 1) return 0;
    ModInt b = 1;
    while (b.power((mod - 1) / 2) == 1) b += 1;
    int e = 0, m = mod - 1;
    while (m % 2 == 0) m >>= 1, e++;
    ModInt x = power((m - 1) / 2), y = (*this) * x * x;
    x *= (*this);
    ModInt z = b.power(m);
    while (y != 1) {
      int j = 0;
      ModInt t = y;
      while (t != 1) j++, t *= t;
      z = z.power(1LL << (e - j - 1));
      x *= z, z *= z, y *= z;
      e = j;
    }
    return ModInt(std::min(x.val, mod - x.val));
  }
};
using mint = ModInt<MOD>;
// ModInt template ends

template<typename T_vector>
void output_vector(const T_vector &v, bool line_break = false, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
    for (int i = start; i < end; i++) {
      cout << v[i] + (add_one ? 1 : 0) << (line_break ? '\n' : i < end - 1 ? ' ' : '\n');
    }
}

void solve() {
    int n, k; cin >> n >> k;
    vi p(n), inv_p(n + 1);
    READ(p);
    REP(i, n) inv_p[p[i]] = i;
    inv_p[n] = -1;
    int diff = 0;
    REP(i, n - 1) {
        int x = p[i];
        int y = p[i + 1];
        diff += inv_p[x + 1] > inv_p[y + 1];
    }
    mint m = k - diff + n - 1;
    OUT(m.nCr(n));
}
 
int main() {
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