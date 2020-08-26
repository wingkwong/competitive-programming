/*
Course Schedule IV

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have direct prerequisites, for example, to take course 0 you have first to take course 1, which is expressed as a pair: [1,0]

Given the total number of courses n, a list of direct prerequisite pairs and a list of queries pairs.

You should answer for each queries[i] whether the course queries[i][0] is a prerequisite of the course queries[i][1] or not.

Return a list of boolean, the answers to the given queries.

Please note that if course a is a prerequisite of course b and course b is a prerequisite of course c, then, course a is a prerequisite of course c.

 

Example 1:


Input: n = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
Output: [false,true]
Explanation: course 0 is not a prerequisite of course 1 but the opposite is true.
Example 2:

Input: n = 2, prerequisites = [], queries = [[1,0],[0,1]]
Output: [false,false]
Explanation: There are no prerequisites and each course is independent.
Example 3:


Input: n = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
Output: [true,true]
Example 4:

Input: n = 3, prerequisites = [[1,0],[2,0]], queries = [[0,1],[2,0]]
Output: [false,true]
Example 5:

Input: n = 5, prerequisites = [[0,1],[1,2],[2,3],[3,4]], queries = [[0,4],[4,0],[1,3],[3,0]]
Output: [true,false,true,false]
*/

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Using Floyd Warshall Algorithm
        //---------------------------------
        // Applications:
        // To find the shortest path is a directed graph
        // To find the transitive closure of directed graphs
        // To find the Inversion of real matrices
        // For testing whether an undirected graph is bipartite
        //---------------------------------
        // Time : O(n^3) 
        // Space: O(n^2) 
        //---------------------------------
        // n = no of vertices
        // A = matrix of dimension n*n
        // for k = 1 to n
        //     for i = 1 to n
        //         for j = 1 to n
        //             Ak[i, j] = min (Ak-1[i, j], Ak-1[i, k] + Ak-1[k, j])
        // return A
        vector<bool> ans;
        vector<vector<bool>> c(n,vector<bool>(n,false));
        for(auto& p:prerequisites) c[p[0]][p[1]]=true;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    c[i][j]=c[i][j]||(c[i][k]&&c[k][j]);
                    // or if (c[i][k]+c[k][j]<c[i][j]) c[i][j]=c[i][k]+c[k][j];  
                }
            }
        }
        for(auto& q:queries) ans.push_back(c[q[0]][q[1]]);
        return ans;
    }
};

class Solution2 {
public:
    bool helper(int u, int v){
        // base case. if v is reachable from u, return true
        if(u==v) return true;
        // a queue for bfs
        list<int> q;
        // set the current node as "visited"
        vis[u]=1;
        // enqueue the current node 
        q.push_back(u);
        while(!q.empty()){
            // dequeue a vertex 
            u=q.front();
            q.pop_front();
            // get all adjacent vertices of u
            for(auto lt=g[u].begin();lt!=g[u].end();lt++){
                // if it is v, that means it is reachable, return true
                if(*lt==v) return true;
                // if it is not visited
                if(!vis[*lt]){
                    // mark it as visited 
                    vis[*lt]=1;
                    // and put it to the queue
                    q.push_back(*lt);
                }
            }
        }
        // cannot be reachable
        return false;
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // BFS Approach
        vector<bool> ans;
        g.resize(n);
        vis.assign(n,0);
        for(auto& p:prerequisites) g[p[0]].push_back(p[1]);
        for(auto q:queries){
           if(helper(q[0],q[1])) ans.push_back(true);
            else ans.push_back(false);
            vis.assign(n,0);
        }
        
        return ans;
    }
private:
    vector<vector<int>> g;
    vector<int> vis;
};