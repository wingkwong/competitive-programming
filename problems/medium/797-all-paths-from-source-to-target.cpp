/*
All Paths From Source to Target

Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:

The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.
*/

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // bfs approach
        vector<vector<int>> ans;
        queue<pair<int, vector<int>>> q;
        // starting from node 0
        q.push({0,vector<int>{0}});
        int goal_node = graph.size();
        while(!q.empty()){
            auto [cur_node, cur_path] = q.front();
            q.pop();
            // check if the current node is the goal node (graph.size()-1)
            if(cur_node == goal_node-1){
                // if so, put the current path to ans
                ans.emplace_back(cur_path);
                continue;
            }
            // if not, traverse those connected nodes
            for(auto next_node: graph[cur_node]){
                vector<int> next_path(cur_path);
                next_path.emplace_back(next_node);
                q.push({next_node, next_path});
            }
        }
        return ans;
    }
};