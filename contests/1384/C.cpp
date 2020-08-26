/*
Codeforces Round #659 (Div. 2) - C. String Transformation 1
https://codeforces.com/contest/1384/problem/C
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

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

int main()  
{ 
    FAST_INP;
    int n,t;
    cin >> t;
    string s1,s2;
    while(t--){
        cin >> n >> s1 >> s2;
        dsu d(26);
        int ans=0;
        for(int i=0;i<n;i++){
        	if(s1[i]>s2[i]){
        		ans=-1;
        		break;
			}
			if(d.unite((int)(s1[i]-'a'), (int)(s2[i]-'a'))) {
				ans++;
			}
		}
		cout << ans << endl;
    }
    return 0;
} 
