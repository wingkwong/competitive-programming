/*
Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
*/

// Topological Sorting

// This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
// Topological sort could also be done via BFS.


// BFS approach
// simplified version of Solution 3 
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses), bfs;
        vector<vector<int>> g;
        g.resize(numCourses);
        for(auto& p:prerequisites) {
            g[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) bfs.push_back(i);
        }
        
        for(int i=0;i<bfs.size();i++){
            for(int j:g[bfs[i]]){
                if(--indegree[j]==0) bfs.push_back(j);
            }
        }
        return bfs.size()==numCourses;
    }
};

// DFS approach
class Solution2 {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        g.resize(numCourses);
        c.assign(numCourses,0);
        for(auto& p:prerequisites)  g[p[0]].push_back(p[1]);
        
        for(int i=0;i<numCourses;i++){
            if(c[i]==0) {
                if(!dfs(i)) return false;
            }
        }
        return true;
    }
private:
    vector<vector<int>> g;
    vector<int> c;
    bool dfs(int u){
        if(c[u]==2) return true;
        c[u]=1;
        for(auto v:g[u]){
            if(c[v]==2) continue;
            if(c[v]==1||!dfs(v)) return false;
        }
        c[u]=2;
        return true;
    }
};


// using Kahn’s algorithm
// L ← Empty list that will contain the sorted elements
// S ← Set of all nodes with no incoming edge

// while S is not empty do
//     remove a node n from S
//     add n to tail of L
//     for each node m with an edge e from n to m do
//         remove edge e from the graph
//         if m has no other incoming edges then
//             insert m into S

// if graph has edges then
//     return error   (graph has at least one cycle)
// else 
//     return L   (a topologically sorted order)
class Solution3 {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> g;
        g.resize(numCourses);
        for(auto& p:prerequisites) g[p[0]].push_back(p[1]);
        for(int i=0;i<numCourses;i++){
            for(auto lt=g[i].begin();lt!=g[i].end();lt++){
                indegree[*lt]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            // if you wanna see the result, use another vector to push_back u
            int u=q.front();
            q.pop();
            for(auto lt=g[u].begin();lt!=g[u].end();lt++){
                if(--indegree[*lt]==0) q.push(*lt);
            }
            cnt++;
        }
        return cnt==numCourses;
    }
};