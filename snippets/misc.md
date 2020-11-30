## Inline function

```cpp
function<void(int,int,int)> f = [&](int a, int b, int c)
{
  // logic
};
```

## Large Numbers

```cpp
const int MOD = 998244353;

ll add(ll x, ll y) {
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

ll sub(ll x, ll y) {
  return (((x - y) % MOD) + MOD) % MOD;
}

ll mul(ll x, ll y) {
    return (x * 1ll * y) % MOD;
}

ll binpow(ll x, ll y) {
    ll ans = 1;
    while(y > 0)
    {
        if(y % 2 == 1) ans = mul(ans, x);
        x = mul(x, x);
        y /= 2;
    }
    return ans;
}

ll divide(int x, int y) {
    return mul(x, binpow(y, MOD - 2));
}
```