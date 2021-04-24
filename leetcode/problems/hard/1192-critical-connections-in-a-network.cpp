/*
Critical Connections in a Network
https://leetcode.com/problems/critical-connections-in-a-network/

There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:



Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
 

Constraints:

1 <= n <= 10^5
n-1 <= connections.length <= 10^5
connections[i][0] != connections[i][1]
There are no repeated connections.
*/

class Solution {
public:
    struct TarjanBridge : vector<vector<int>> {
      vector<int> low;
      vector<int> parent;
      vector<int> discovery;
      vector<vector<int>> bridge;

      TarjanBridge() {}
      TarjanBridge(vector<vector<int>>& G) {
        int n = (int) G.size();
        low.resize(n, -1);
        parent.resize(n, -1);
        discovery.resize(n, -1);
        for(int i = 0; i < n; i++) {
          if(discovery[i] == -1) {
            dfs(i, discovery, low, parent, G, bridge);
          }
        }
      }

      void dfs(int i, vector<int>& discovery, vector<int>& low, vector<int>& parent, vector<vector<int>>& G, vector<vector<int>>&  bridge) {
        static int time = 0;
        discovery[i] = time;
        low[i] = time;
        time++;
        for(auto x : G[i]) {
          if(discovery[x] == -1) {
            parent[x] = i;
            dfs(x, discovery, low, parent, G, bridge);
            low[i] = min(low[i], low[x]);
            if(low[x] > discovery[i]) {
              bridge.push_back({i, x});
            }
          } else {
            if(x != parent[i]) {
              low[i] = min(low[i], discovery[x]);
            }
          }
        }
      }
    };

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n);
        for(auto c : connections) {
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }
        TarjanBridge tarjan(g);
        return tarjan.bridge;
    }
};