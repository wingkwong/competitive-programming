/*
Course Schedule II

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> ans;
        for(auto p:prerequisites){
            g[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(auto v:g[u]){
                if(--indegree[v]==0){
                    q.push(v);
                }
            }
        }
        if(ans.size()!=numCourses) return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

class Solution2 {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // this solution can pass Leetcode test cases
        // however, it may cause TLE if the numbers go larger
        // use the first solution for larger constraints 
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> ans;
        for(auto p:prerequisites) {
            // build the graph
            graph[p[1]].push_back(p[0]);
            // cnt indegree
            indegree[p[0]]++;
        }
        for(int i=0;i<numCourses;i++){
            int j=0;
            // search for the index j where indegree[j] = 0
            for(;j<numCourses;j++){
                if(indegree[j]==0){
                    break;
                }
            }
            // return {} if no such result
            if(j==numCourses) return {};
            // deduct indegree[j] by 1 so that it won't be visited again
            indegree[j]--;
            // reduce the in-degree of each neighbor by 1
            for(auto to:graph[j]) {
                indegree[to]--;
            }
            // store the ans
            ans.emplace_back(j);
        }
        return ans;
    }
};