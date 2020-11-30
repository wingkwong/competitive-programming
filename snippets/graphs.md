## find the max probability from start to end

```cpp
vector<vector<pair<int,int>>> g(n);
for(int i=0;i<edges.size();i++){
    if(succProb[i]!=0){
        g[edges[i][0]].push_back({edges[i][1],val[i]});
        g[edges[i][1]].push_back({edges[i][0],val[i]});
    }
}

while(!q.empty()){
    vector<int> tmp;
    for(auto from:q){
        for(auto [to, val]:g[from]){
            if(p[to]<p[from]*val){
                p[to]=p[from]*val;
                tmp.emplace_back(to);
            }
        }
    }
    swap(q,tmp);
}
```

## Node Indegree
```cpp
vector<vector<int>> graph(n);
vector<int> indegree(n,0);
vector<int> ans;
for(auto p:prerequisites) {
    graph[p[1]].push_back(p[0]);
    indegree[p[0]]++;
}
for(int i=0;i<n;i++){
    int j=0;
    for(;j<n;j++){
        if(indegree[j]==0){
            break;
        }
    }
    if(j==n) return {};
    indegree[j]--;
    for(auto to:graph[j]) {
        indegree[to]--;
    }
    ans.emplace_back(j);
}
```