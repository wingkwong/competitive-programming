```cpp
struct comb{
  public:
  vector<ll> fac, finv, inv;
  comb(int mxN) {
    fac.resize(mxN);
    finv.resize(mxN);
    inv.resize(mxN);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 1; i < mxN-1; i++) {
      fac[i+1] = fac[i] * (i+1) % MOD;
      inv[i+1] = MOD - inv[MOD%(i+1)]*(MOD/(i+1))%MOD;
      finv[i+1] = finv[i]*inv[i+1] % MOD;
    }
  }

  ll ncr(ll n, ll k) {
    if (k < 0 || n < k) return 0;
    ll res = 1;
    res *= fac[n]*finv[k]%MOD*finv[n-k]%MOD;
    return res;
  }

};
```

### Usage:

```cpp
ll n, k;
cin >> n >> k;
comb c = comb(n);
FORN(i,1,k){
  OUT((c.ncr(n-k+1,i)*c.ncr(k-1,i-1)%MOD));
}
```