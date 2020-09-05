/*
Connected Cities
https://binarysearch.io/problems/Connected-Cities

You are given n cities represented as an integer in [0, n) and a list of one-way roads that connects one city to another.

Return whether you can reach any city from any city.

Example 1
Input

n = 2
roads = [
    [0, 1],
    [1, 0]
]
Output

true
Explanation

You can go 0 to 1 and 1 to 0

Example 2
Input

n = 2
roads = [
    [1, 0]
]
Output

false
Explanation

You can go 1 to 0 but not 0 to 1
*/

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<vector<int>> g, gr;
    vector<int> vis;
    int cnt;
    
    void dfs(int u, vector<vector<int>>& g){
        vis[u]=1;
        cnt++;
        for(int v: g[u]){
            if(!vis[v]){
                dfs(v,g);
            }
        }
    }
    
    bool ok(vector<vector<int>>& g, int n){
        vis.assign(n,0);
        cnt=0;
        dfs(0,g);
        return cnt==n;
    }
    
    bool solve(int n, vector<vector<int>>& roads) {
        // Return whether you can reach any city **from any city**.
        // idea: dfs the whole path to see if the count is same as n 
        // you can also solve this question with kosaraju's algorithm
        // but you will need 2 dfs functions and a stack
        if(n==0) return true;
        g.resize(n), gr.resize(n);
        for(auto r: roads) g[r[0]].push_back(r[1]), gr[r[1]].push_back(r[0]);
        return ok(g,n)&&ok(gr,n);
    }
};
