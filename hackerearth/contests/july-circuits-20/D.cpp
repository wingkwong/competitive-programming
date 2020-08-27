/*
July Circuits '20 - Separating Numbers
https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/separating-numbers-6fe976a9
*/

#include <bits/stdc++.h>
using namespace std; 
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define ll long long 
#define ld long double
#define vi deque<int>
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define iii pair<int,ii>
#define il pair<int,ll>
#define pll pair<ll,ll>
#define _path pair<ll,pair<ll,int> > 
#define vv deque
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
const int MAXN = 3e5+5;
const ll INF = 1e18;
vi g[MAXN];

struct DSU{
	int parent[MAXN];
	int sz[MAXN];
	map<int,ll> mp[MAXN];
	DSU(int* arr,int n){
		FOR(i,n)parent[i] = i;
		FOR(i,n)sz[i] = 1;
		FOR(i,n)mp[i][arr[i]] = 1;
	}
	int find(int a){
		if(parent[a] != a)parent[a] = find(parent[a]);
		return parent[a];
	}
	ll merge(int a,int b){
		int pa = find(a);
		int pb = find(b);
		ll sum = 0;
		if(sz[pa] < sz[pb])swap(pa,pb);
		for(auto e: mp[pb]){
			sum += e.ss*mp[pa][e.ff];
			mp[pa][e.ff] += e.ss;
		}
		sz[pa] += sz[pb];
		parent[pb] = pa;
		mp[pb].clear();
		return sum;
	}
};
void solve(){
	int n,q;
	cin >> n;
	q = n-1;
	ii edge[n];
	FOR(i,n-1){
		int a,b;
		cin >> a >> b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
		edge[i] = {a,b};
	}
	int colors[n];
	FOR(i,n) cin >> colors[i];
	DSU dsu(colors,n);
	int queries[q];
	FOR(i,q){
		int x;
		cin >> x;
		x--;
		queries[i] = x;
	}
	ll ans[q];
	for(int i =q-1;i>=0;i--){
		ans[i]=dsu.merge(edge[queries[i]].ff,edge[queries[i]].ss);
	}
	FOR(i,q) cout << ans[i] << endl;
}
int main(){
	FAST_INP;
	int t = 1;
	while(t--) solve();
	return 0;
}