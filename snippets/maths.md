## ModInt

```cpp
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
```

### Usage 

```cpp
mint ans = 0;
vector<mint> dp(s + 1);
```

## Primes

check if n is a prime number

```cpp
bool isPrime(long long n) {
  assert(n >= 2 && "N must be greater or equal to 2");
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
```

## Sieve of Eratosthenes

```cpp
vector<bool> seiveOfEratosthenes(const int n) {
  assert(n >= 2 && "N must be greater or equal to 2");
  vector<bool> isPrime(n + 1, true);
  for (int i = 2; i * i <= n; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }
  return isPrime;
}
```


## Check how many prime numbers <= N

```cpp
// using Sieve of Eratosthenes
int cntPrime(int n) {
  vector<bool> isPrime = seiveOfEratosthenes(n);
  for (int i = 2; i <= n; i++) cnt += isPrime[i] == true;
  return cnt;
}
```

## Fast Pow

```cpp
long long fastpow(long long base, long long exp) {
  long long res = 1;
  while (exp > 0) {
    // if n is odd, a ^ n can be seen as a ^ (n / 2) * a ^ (n / 2) * a
    if (exp & 1) res *= base;
    // if n is even, a ^ n can be seen as a ^ (n / 2) * a ^ (n / 2)
    base *= base;
    exp >>= 1;
  }
  return res;
}
```

## Pow with mod

```cpp
long long modpow(long long base, long long exp, long long mod) {
  base %= mod;
  long long res = 1;
  while (exp > 0) {
    if (exp & 1) res = (res * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return res;
}
```

## Prime Seive 

```cpp
// prime_sieve starts
vector<int> prime_sieve(const int N, const int Q = 17, const int L = 1 << 15) {
  using u8 = unsigned char;
  static const int rs[] = {1, 7, 11, 13, 17, 19, 23, 29};
  struct P {
    P(int p) : p(p) {}
    int p;
    int pos[8];
  };
  auto approx_prime_count = [](const int N) -> int {
    return N > 60184 ? N / (log(N) - 1.1) : max(1., N / (log(N) - 1.11)) + 1;
  };

  const int v = sqrt(N), vv = sqrt(v);
  vector<bool> isp(v + 1, true);
  for (int i = 2; i <= vv; ++i)
    if (isp[i]) {
      for (int j = i * i; j <= v; j += i) isp[j] = false;
    }

  const int rsize = approx_prime_count(N + 30);
  vector<int> primes = {2, 3, 5};
  int psize = 3;
  primes.resize(rsize);

  vector<P> sprimes;
  size_t pbeg = 0;
  int prod = 1;
  for (int p = 7; p <= v; ++p) {
    if (!isp[p]) continue;
    if (p <= Q) prod *= p, ++pbeg, primes[psize++] = p;
    auto pp = P(p);
    for (int t = 0; t < 8; ++t) {
      int j = (p <= Q) ? p : p * p;
      while (j % 30 != rs[t]) j += p << 1;
      pp.pos[t] = j / 30;
    }
    sprimes.push_back(pp);
  }

  vector<u8> pre(prod, 0xFF);
  for (size_t pi = 0; pi < pbeg; ++pi) {
    auto pp = sprimes[pi];
    const int p = pp.p;
    for (int t = 0; t < 8; ++t) {
      const u8 m = ~(1 << t);
      for (int i = pp.pos[t]; i < prod; i += p) pre[i] &= m;
    }
  }

  const int block_size = (L + prod - 1) / prod * prod;
  vector<u8> block(block_size);
  u8 *pblock = block.data();
  const int M = (N + 29) / 30;

  for (int beg = 0; beg < M; beg += block_size, pblock -= block_size) {
    int end = min(M, beg + block_size);
    for (int i = beg; i < end; i += prod) {
      copy(pre.begin(), pre.end(), pblock + i);
    }
    if (beg == 0) pblock[0] &= 0xFE;
    for (size_t pi = pbeg; pi < sprimes.size(); ++pi) {
      auto &pp = sprimes[pi];
      const int p = pp.p;
      for (int t = 0; t < 8; ++t) {
        int i = pp.pos[t];
        const u8 m = ~(1 << t);
        for (; i < end; i += p) pblock[i] &= m;
        pp.pos[t] = i;
      }
    }
    for (int i = beg; i < end; ++i) {
      for (int m = pblock[i]; m > 0; m &= m - 1) {
        primes[psize++] = i * 30 + rs[__builtin_ctz(m)];
      }
    }
  }
  assert(psize <= rsize);
  while (psize > 0 && primes[psize - 1] > N) --psize;
  primes.resize(psize);
  return primes;
}
// prime_sieve ends
```