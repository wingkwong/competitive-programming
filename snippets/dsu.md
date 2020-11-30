## DSU Template 1

```cpp
class dsu {
private:
    vector<ll> d, sz;
public:
    dsu(ll n) {
        d=vector<ll>(n);
        sz=vector<ll>(n, 1);
        REP(i,n) d[i]=i;
    }

    ll p(ll a) {
        if (d[a]==a) return a;
        else return d[a]=p(d[a]);
    }

    ll get_sz(ll a) {
        return sz[p(a)];
    }

    void unite(ll a, ll b) {
        ll pa=p(a);
        ll pb=p(b);
        if (pa==pb) return;
        else {
            sz[pb]+=sz[pa];
            sz[pa]=0;
            d[pa]=pb;
            return;
        }
        return;
    }
};
```

### Usage:

```cpp
dsu d=dsu(n);
d.unite(a,b);
```

## DSU Template 2

```cpp
class dsu {
 public:
  vector<int> p;
  int n;
 
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
 
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
 
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};
```

### Usage:

```cpp
dsu d(26);
if(d.unite((int)(s1[i]-'a'), (int)(s2[i]-'a'))) {
    // logic
}
```