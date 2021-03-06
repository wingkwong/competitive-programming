## find the max probability from start to end

```cpp
vector<vector<pair<int, int>>> g(n);
for (int i = 0; i < edges.size(); i++) {
  if (succProb[i] != 0) {
    g[edges[i][0]].push_back({edges[i][1], val[i]});
    g[edges[i][1]].push_back({edges[i][0], val[i]});
  }
}

while (!q.empty()) {
  vector<int> tmp;
  for (auto from : q) {
    for (auto[to, val] : g[from]) {
      if (p[to] < p[from] * val) {
        p[to] = p[from] * val;
        tmp.emplace_back(to);
      }
    }
  }
  swap(q, tmp);
}
```

## Node Indegree
```cpp
vector<vector<int>> graph(n);
vector<int> indegree(n, 0);
vector<int> ans;
for (auto p : prerequisites) {
  graph[p[1]].push_back(p[0]);
  indegree[p[0]]++;
}
for (int i = 0; i < n; i++) {
  int j = 0;
  for (; j < n; j++) {
    if (indegree[j] == 0) {
      break;
    }
  }
  if (j == n) return {};
  indegree[j]--;
  for (auto to : graph[j]) {
    indegree[to]--;
  }
  ans.emplace_back(j);
}
```

## Check Bipartition

```cpp
struct is_bipartite {
  int V;
  vector<vector<int>> adj;
  vector<int> depth;
  vector<bool> visited;

  is_bipartite(int v = -1) {
    if (v >= 0) init(v);
  }

  void init(int v) {
    V = v;
    adj.assign(V, {});
  }

  void add(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<array<vector<int>, 2>> components;

  bool dfs(int node, int parent) {
    assert(!visited[node]);
    visited[node] = true;
    depth[node] = parent < 0 ? 0 : depth[parent] + 1;
    components.back()[depth[node] % 2].push_back(node);
    for (int h : adj[node])
      if (h != parent) {
        if (!visited[h] && !dfs(h, node)) return false;
        if (depth[node] % 2 == depth[h] % 2) return false;
      }
    return true;
  }

  bool solve() {
    depth.assign(V, -1);
    visited.assign(V, false);
    components = {};
    for (int i = 0; i < V; i++)
      if (!visited[i]) {
        components.emplace_back();
        if (!dfs(i, -1)) return false;
      }
    return true;
  }
}; 
```

### Usage:

```cpp
// init 
is_bipartite c(N);

// add the edge
for(auto d : dislikes) c.add(--d[0], --d[1]);
 
// check if it is bipartite
bool b = c.solve();

// print out two parts
for(auto c : components[0]) {
    cout << c[0] << " " << c[1] << "\n";
}
```

## Dijkstra

```cpp
const int mxN = 1e5;
vector<pair<long, long>> g[mxN];
long long n, m, dist[mxN];

void dijkstra(int start) {
  priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
  pq.push({start, 0});
  while (!pq.empty()) {
    pair<long, long> p = pq.top();
    long long from = p.first;
    pq.pop();
    for (pair<long, long> p2 : g[from]) {
      long long to = p2.first, cost = p.second + p2.second;
      if (dist[to] > cost) {
        dist[to] = cost;
        pq.push({to, cost});
      }
    }
  }
}
```

### Usage: Find the shortest route from u to v

```cpp
void solve() {
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].push_back({v, w});
  }
  dijkstra(0);
  for(int v = 0; v < n; v++) cout << dist[v] << endl;
}
```

## Dijkstra with Path 

```cpp
// --------------------------- Dijkstra with Path --------------------------- //
const int N = 1e5 + 5;
long long n, m;
long long arrival[N], departure[N], vis[N], parent[N];
vector<pair<long long, long long> > g[N];

void dijkstra_with_path(long long source, long long destination) {
  for (long long i = 1; i <= n; i++) arrival[i] = 1e18, departure[i] = 1e18, vis[i] = 0;
  arrival[source] = 0;
  set<pair<long long, long long> > s;
  s.insert({0, source});
  while (!s.empty()) {
    auto x = *(s.begin());
    s.erase(x);
    vis[x.second] = 1;
    departure[x.second] = arrival[x.second];
    for (auto it : g[x.second]) {
      if (arrival[it.first] > departure[x.second] + it.second) {
        s.erase({arrival[it.first], it.first});
        arrival[it.first] = departure[x.second] + it.second;
        s.insert({arrival[it.first], it.first});
        parent[it.first] = x.second;
      }
    }
  }
  if (!vis[destination]) {
    cout << "-1";
    return;
  }
  long long v = destination;
  vector<long long> ans;
  while (parent[v]) {
    ans.push_back(v);
    v = parent[v];
  }
  ans.push_back(source);
  reverse(ans.begin(), ans.end());
  for (auto it : ans) cout << it << " ";
}
// --------------------------- Dijkstra with Path --------------------------- //
```

## Strongly Connected Components (SCC)

```cpp
struct SCC : vector<int> {
  vector<vector<int>> comps;
  vector<int> S;

  SCC() {}
  SCC(vector<vector<int>>& G) : vector<int>((int)G.size(), -1), S((int)G.size()) {
    for(int i = 0; i < (int)G.size(); i++) if(!S[i]) dfs(G, i);
  }

  int dfs(vector<vector<int>>& G, int v) {
    int low = S[v] = (int)S.size();
    S.push_back(v);
    for(auto e : G[v]) if(at(e) < 0) low = min(low, S[e] ?: dfs(G, e));
    if(low == S[v]) {
      comps.push_back({});
      for(int i = S[v]; i < (int)S.size(); i++) {
        at(S[i]) = (int)comps.size() - 1;
        comps.back().push_back(S[i]);
      }
      S.resize(S[v]);
    }
    return low;
  }
};
```

## Find Bridges (Tarjan's Algorithm)

```cpp
struct TarjanBridge : vector<vector<int>> {
  vector<int> low;
  vector<int> discovery;
  vector<vector<int>> bridge;
  vector<vector<int>> G;

  TarjanBridge() {}
  TarjanBridge(vector<vector<int>>& G) {
    this->G = G;
    int n = (int) G.size();
    low.resize(n, -1);
    discovery.resize(n, -1);
    for(int i = 0; i < n; i++) {
      if(discovery[i] == -1) {
        dfs(i, i);
      }
    }
  }

  void dfs(int u, int p) {
    static int time = 0;
    discovery[u] = time;
    low[u] = time;
    time++;
    for(auto v : G[u]) {
      if(v ^ p) {
        if(discovery[v] == -1) {
          // recursive DFS
          dfs(v, u);
          // low[v] might be an ancestor of u
          low[u] = min(low[u], low[v]);
          // bridge found
          if(discovery[u] < low[v]) {
            bridge.push_back({u, v});
          }
        } else {
          // v was discovered -> found an ancestor
          // find the ancestor with the least discovery time
          low[u] = min(low[u], discovery[v]);
        }
      }
    }
  }
};

```

### Example:

```cpp
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> g(n);
    for(auto c : connections) {
        g[c[0]].push_back(c[1]);
        g[c[1]].push_back(c[0]);
    }
    TarjanBridge tarjan(g);
    return tarjan.bridge;
}
```

## Topological Sort

```cpp
// --------------------------- Topological Sort  --------------------------- //
const int N = 500 + 5;
long long n, m;
long long indegree[N], indegree2[N];
vector<long long> g[N];
 
bool topological_sort() {
	long long res = 0;
	queue<long long> q;
	vector<long long> orders;
	for(int i = 1; i <= n; i++) {
		if(indegree[i] == 0) {
			q.push(i);
			orders.push_back(i);
		}
	}
	while(!q.empty()) {
		auto u = q.front(); q.pop();
		for(auto v : g[u]) {
			if(--indegree[v] == 0) {
				q.push(v);
				orders.push_back(v);
			}
		}
		res++;
	}
	// output_vector(orders);
	return res == n;
}
// --------------------------- Topological Sort  --------------------------- //
```

### Example:

```cpp
void solve() {
    cin >> n >> m;
    REPN(i, m) {
        ll a, b; cin >> a >> b;
        g[a].pb(b);
		    indegree[b]++;
    }
	// indegree2 <-- indegree
	memcpy(indegree2, indegree, sizeof(indegree));
	if(topological_sort()) {
		OUT("YES");
		return;
	}
	REPN(i, n) {
		// indegree <-- indegree2
		memcpy(indegree, indegree2, sizeof(indegree2));
		if(indegree[i] > 0) {
			--indegree[i];
			if(topological_sort()) {
				OUT("YES");
				return;
			}
		}
	}
	OUT("NO");
}
```
