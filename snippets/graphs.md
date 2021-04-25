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