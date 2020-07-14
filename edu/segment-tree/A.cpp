/*
ITMO Academy: pilot course - Segment Tree - A. Segment Tree for the Sum
https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

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


int main()
{
    FAST_INP;
    int n,m,v;
    cin >> n >> m;
    segtree st;
    st.init(n);
    for(int i=0;i<n;i++){
        cin >> v;
        st.set(i,v);
    }

    for(int i=0;i<m;i++){
        int op;
        cin >> op;
        if(op==1) {
            int i,v;
            cin >> i >> v;
            st.set(i,v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.sum(l,r) << endl;
        }
    }

	return 0;
}

