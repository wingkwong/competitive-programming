## Post-order traversal

```cpp
void postOrder(Node* root, vector<int>& res){
    if(!root) return;
    for(auto c:root->children) postOrder(c,res);
    res.emplace_back(root->val);
}
```

## Pre-order traversal

```cpp
void preOrder(Node* root, vector<int>& res){
    if(!root) return;
    res.emplace_back(root->val);
    for(auto c:root->children) preOrder(c,res);
}
```

## Segment Tree

```cpp
struct segtree {
    int size;
    vector<long long> sums;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        sums.assign(2*size,0LL);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            sums[x]=v;
            return;
        }

        int m = (lx+rx)/2;
        if(i<m) set(i,v,2*x+1,lx,m);
        else set(i,v,2*x+2,m,rx);
        sums[x] = sums[2*x+1]+sums[2*x+2];
    }

    void set(int i, int v){
        set(i, v, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lx, int rx){
        // no intersection
        if(lx>=r||l>=rx) return 0;
        // inside
        if(lx>=l&&rx<=r) return sums[x];
        // go to both left and right side
        int m=(lx+rx)/2;
        long long s1 = sum(l,r,2*x+1,lx,m);
        long long s2 = sum(l,r,2*x+2,m,rx);
        return s1+s2;
    }

    long long sum(int l, int r){
        return sum(l,r,0,0,size);
    }
    
};
```

### Usage:

```cpp
segtree st;
// init segtree
st.init(n);
vector<int> a(n);
// update value and recalculate the sum
int v;
for(int i=0;i<n;i++){
  cin >> v;
  st.set(i,v);
}
// get the range sum
cout << st.sum(l,r) << endl;
```


```cpp
// segment tree - template starts
template <typename T = long long>
struct SegmentTree
{
    using F = function<T(T, T)>;
#define clz(x) __builtin_clz(x)

    SegmentTree(int n, const F f, const T &unit) : f(f), unit(unit), sz(n - 1 ? 1 << (32 - clz(n - 1)) : 1)
    {
        seg.assign(2 * sz, unit);
    }

    SegmentTree(vector<T> &a, const F f, const T &unit) : f(f), sz((int)a.size() > 1 ? 1 << (32 - clz(a.size() - 1)) : 1), unit(unit)
    {
        int n0 = a.size();
        seg.assign(2 * sz, unit);
        for (int i = 0; i < n0; ++i)
            seg[i + sz] = a[i];
        for (int i = sz - 1; i > 0; --i)
            seg[i] = f(seg[i << 1], seg[(i << 1) | 1]);
    }
    const int sz;
    vector<T> seg;
    const F f;
    const T unit;

    void set(int k, T x) { seg[k + sz] = x; }

    void build()
    {
        for (int i = sz - 1; i > 0; --i)
            seg[i] = f(seg[i << 1], seg[(i << 1) | 1]);
    }

    T query(int l, int r)
    {
        T x = unit;
        for (int d = r - l; d >= 1; d = r - l)
        {
            int L = l | ((1U << 31) >> clz(d));
            int k = __builtin_ctz(L);
            x = f(x, seg[(sz | l) >> k]);
            l += L & (-L);
        }
        return x;
    }

    void update(int i, T x)
    {
        int k = i + sz;
        seg[k] = x;
        for (k = k >> 1; k > 0; k >>= 1)
        {
            seg[k] = f(seg[k << 1], seg[(k << 1) | 1]);
        }
    }

    void add(int i, T x)
    {
        int k = i + sz;
        seg[k] += x;
        for (k = k >> 1; k > 0; k >>= 1)
        {
            seg[k] = f(seg[k << 1], seg[(k << 1) | 1]);
        }
    }
    SegmentTree() = default;
    T operator[](int k) const { return seg[sz + k]; }
};
// segment tree - templates ends
```

### Usage:
```cpp
// calculate XOR value within given range
SegmentTree<int> seg(a, [](int x, int y) { return x ^ y; }, 0);
seg.update(x - 1, seg[x - 1] ^ y)
OUT(seg.query(x - 1, y));
```


## Binary Lifting

```cpp
// --------------------------------
// binary lifting starts 
// --------------------------------
const int mxN = 200005;
const int mxNode = 19; // log2(mxN) + 2
vi g[mxN];
int d[mxN], up[mxN][mxNode];

void dfs(int u, int p) {
  up[u][0] = p;
  for(int i = 1; i < mxNode; i++) {
    up[u][i] = ~up[u][i - 1] ? up[up[u][i - 1]][i - 1] : -1;
  }
  for(int v : g[u]){
      if(v ^ p){
          d[v] += d[u] + 1;
          dfs(v, u);
      }
  }
}

int lift(int x, int k) {
  // find the k-th ancestor of x
  for(int i = mxNode; ~i; i--) {
    if((1 << i) & k) {
      x = up[x][i];    
    }
  }
  return x;
}
// --------------------------------
// binary lifting ends
// --------------------------------

```


## Lower Common Ancestor (LCA)

```cpp
// --------------------------------
// LCA starts 
// --------------------------------
const int mxN = 200005;
const int mxNode = 19; // log2(mxN) + 2
vi g[mxN];
int d[mxN], up[mxN][mxNode];

void dfs(int u, int p) {
  up[u][0] = p;
  for(int i = 1; i < mxNode; i++) {
    up[u][i] = ~up[u][i - 1] ? up[up[u][i - 1]][i - 1] : -1;
  }
  for(int v : g[u]){
      if(v ^ p){
          d[v] += d[u] + 1;
          dfs(v, u);
      }
  }
}

int lca(int u, int v) {
  // swap u and v if v is farther than root node
  if(d[u] < d[v]) swap(u, v);
  // find the ancestor of u which has the same level as v
  for(int i = mxNode - 1; ~i; i--) {
    if(d[u] - (1 << i) >= d[v]) {
        u = up[u][i];
    }
  }
  // if v is the ancestor of u, then v is the LCA of u
  if(u == v) return u;
  // find a node which is not a common ancestor of u and v but up[x][0]
  for(int i = mxNode - 1; ~i; i--) {
    if(up[u][i] ^ up[v][i]) {
      u = up[u][i], v = up[v][i];
    }
  } 
  return up[u][0];
}
// --------------------------------
// LCA ends
// --------------------------------
```

## Binary Lifting

```cpp
// --------------------------------
// binary lifting starts 
// --------------------------------
const int mxN = 200005;
const int mxNode = 30; // ~ log2(k) 
vi g[mxN];
int up[mxN][mxNode];

void binary_lifting() {
  for(int i = 1; i < mxNode; i++) {
    for(int u = 0; u < mxN; u++) {
      up[u][i] = up[up[u][i - 1]][i - 1];
    }
  }
}

int kth_ancestor(int u, int k) {
  for(int i = 0; i < mxNode; i++) {
    if(k & (1 << i)) u = up[u][i];
  }
  return u;
}
// --------------------------------
// binary lifting ends
// --------------------------------
```