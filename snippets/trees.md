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

### Usages:

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
