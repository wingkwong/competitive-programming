/*
Number of Connected Components in an Undirected Graph
https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.

 

Example 1:


Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
Example 2:


Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1
 

Constraints:

1 <= n <= 2000
1 <= edges.length <= 5000
edges[i].length == 2
0 <= ai <= bi < n
ai != bi
There are no repeated edges.
*/

class Solution {
public:
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

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        SCC s = SCC(g);
        return s.comps.size();
    }
};