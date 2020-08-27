#include<bits/stdc++.h>
#define int long long int
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int poww(int n,int p) {
  int power=1;
  for(int i=0;i<p;i++) power=power*n;
  return power;
}

int32_t main()
{
  FAST_INP;
  int t; cin >> t;
  while(t--) {
    int n,cnt=0;
    cin >> n;
    vector<int> v;
    while(n) {
      if(n&1) v.push_back(poww(3,cnt));
      n=n>>1;
      cnt++;
    }
    cout << v.size() << '\n';
    for(int i=0;i<v.size();i++) cout << v[i] << " ";
    cout << '\n';
  }
}