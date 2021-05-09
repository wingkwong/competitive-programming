/*
Largest Color Value in a Directed Graph
https://leetcode.com/problems/largest-color-value-in-a-directed-graph/

There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.


Example 1:

Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
Output: 3
Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).

Example 2:

Input: colors = "a", edges = [[0,0]]
Output: -1
Explanation: There is a cycle from 0 to 0.
 

Constraints:

n == colors.length
m == edges.length
1 <= n <= 105
0 <= m <= 105
colors consists of lowercase English letters.
0 <= aj, bj < n
*/

class Solution {
public:
    int cycle = 0, ans = 0;
    void dfs(string& colors, vector<vector<int>>& cnt, vector<vector<int>>& adj, vector<int>& ok, vector<int>& vis, int u) {
        vis[u] = 1;
        for(auto v : adj[u]) {
            if(vis[v]) {
                cycle = 1;
                continue;
            }
            if(ok[v]) {
                for(int i = 0; i < 26; i++) {
                    cnt[u][i] = max(cnt[u][i], cnt[v][i]);
                }
                continue;
            }
            dfs(colors, cnt, adj, ok, vis, v);
            for(int i = 0; i < 26; i++) {
                cnt[u][i] = max(cnt[u][i], cnt[v][i]);
            }
        }
        ans = max(ans, ++cnt[u][colors[u] - 'a']);
        vis[u] = 0;
        ok[u] = 1;
    }
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();   
        vector<int> ok(n, 0), vis(n, 0);
        vector<vector<int>> adj(n);
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        vector<vector<int>> cnt(n, vector<int>(26)); // [node][color]
        for(int v = 0; v < n; v++) {
            if(!ok[v]) {
                dfs(colors, cnt, adj, ok, vis, v);
            }
        }
        if(cycle) return -1;
        return ans;
    }
};


// TLE
// class Solution {
// public:
//     int dfs(string& colors, vector<int>& cnt, vector<vector<int>>& adj, vector<int>& no_indegree, int u) {
//         int res = ++cnt[colors[u] - 'a'];
//         for(auto v : adj[u]) {
//             res = max(res, dfs(colors, cnt, adj, no_indegree, v));
//         }
//         --cnt[colors[u] - 'a'];
//         no_indegree[u] = 0;
//         return res;
//     }
    
//     int largestPathValue(string colors, vector<vector<int>>& edges) {
//         int n = colors.size(), ans = -1;    
//         vector<int> no_indegree(n, 1);
//         vector<vector<int>> adj(n);
//         for(auto e : edges) {
//             adj[e[0]].push_back(e[1]);
//             no_indegree[e[1]] = 0;
//         }
//         vector<int> cnt(26, 0);
//         for(int v = 0; v < n; v++) {
//             if(no_indegree[v]) {
//                 ans = max(ans, dfs(colors, cnt, adj, no_indegree, v));
//             }
//         }
//         return ans;
//     }
// };