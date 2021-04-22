/*
Connecting Cities With Minimum Cost
https://leetcode.com/problems/connecting-cities-with-minimum-cost/

There are N cities numbered from 1 to N.

You are given connections, where each connections[i] = [city1, city2, cost] represents the cost to connect city1 and city2 together.  (A connection is bidirectional: connecting city1 and city2 is the same as connecting city2 and city1.)

Return the minimum cost so that for every pair of cities, there exists a path of connections (possibly of length 1) that connects those two cities together.  The cost is the sum of the connection costs used. If the task is impossible, return -1.

 

Example 1:



Input: N = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
Output: 6
Explanation: 
Choosing any 2 edges will connect all cities so we choose the minimum 2.
Example 2:



Input: N = 4, connections = [[1,2,3],[3,4,4]]
Output: -1
Explanation: 
There is no way to connect all cities even if all edges are used.
 

Note:

1 <= N <= 10000
1 <= connections.length <= 10000
1 <= connections[i][0], connections[i][1] <= N
0 <= connections[i][2] <= 10^5
connections[i][0] != connections[i][1]
*/

class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    int minimumCost(int N, vector<vector<int>>& connections) {
    	// Kruskal's algorithm
    	// https://en.wikipedia.org/wiki/Kruskal%27s_algorithm
        parent.resize(N + 1);
        sort(connections.begin(), connections.end(), [&](vector<int>&a, vector<int>& b){
            return a[2] < b[2];
        });
        for(int i = 1; i <= N; i++) {
            parent[i] = i;
        }
        int ans = 0, cnt = 1;
        for(auto c : connections) {
            int x = find(c[0]), y = find(c[1]);
            if(x != y) {
                ans += c[2];
                cnt += 1;
                parent[y] = x;
            }
            if(cnt == N) return ans;
        }
        return -1;
    }
};