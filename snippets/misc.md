## Output Vector

```cpp
template<typename T_vector>
void output_vector(const T_vector &v, bool line_break = false, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
    for (int i = start; i < end; i++) {
      cout << v[i] + (add_one ? 1 : 0) << (line_break ? '\n' : i < end - 1 ? ' ' : '\n');
    }
}
```

## Inline function

```cpp
function<void(int,int,int)> f = [&](int a, int b, int c)
{
  // logic
};
```

```cpp
auto f = [&](int a, int b, int c) {
    // logic
};
```


## Large Numbers

```cpp
const int MOD = 998244353;

long long add(long long x, long long y) {
  x += y;
  while (x >= MOD) x -= MOD;
  while (x < 0) x += MOD;
  return x;
}

long long sub(long long x, long long y) {
  return (((x - y) % MOD) + MOD) % MOD;
}

long long mul(long long x, long long y) { return (x * 1LL* y) % MOD; }

long long binpow(long long x, long long y) {
  long long ans = 1;
  while (y > 0) {
    if (y % 2 == 1) ans = mul(ans, x);
    x = mul(x, x);
    y /= 2;
  }
  return ans;
}

long long divide(int x, int y) { return mul(x, binpow(y, MOD - 2)); }
```

## Random number generator

```
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
```