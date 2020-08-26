/*
Minimum Time to Collect All Apples in a Tree

Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend in order to collect all apples in the tree starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [fromi, toi] means that exists an edge connecting the vertices fromi and toi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple, otherwise, it does not have any apple.

Example 1:

Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
Output: 8 
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
Example 2:

Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
Output: 6
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
Example 3:

Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
Output: 0
 
Constraints:

1 <= n <= 10^5
edges.length == n-1
edges[i].length == 2
0 <= fromi, toi <= n-1
fromi < toi
hasApple.length == n
*/

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int sz = (int)edges.size();
        int ans=0;
        // find out all the node that has apple and set the parent node to true 
        for(int i=sz-1;i>=0;i--){
            if(hasApple[edges[i][1]]) {
                ans+=2;
                hasApple[edges[i][0]]=true;
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int sz = (int)edges.size();
        // build the graph
        for(auto edge:edges) m[edge[0]].push_back(edge[1]);
        // dsf approach
        return dsf(0,0,hasApple);
    }
private:
    unordered_map<int,vector<int>> m;
    int dsf(int node,int curCost,vector<bool>& hasApple){
        int cost = 0;
        // traverse all nodes
        for(int k:m[node]) cost+=dsf(k,2,hasApple);
        // if no child has apples, cost will be 0
        if(!hasApple[node]&&!cost) return 0;
        return cost+curCost;
    }
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

//         0
//     1       3
// 2

// 7
// [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]
// [false,false,true,false,true,true,false]
// 7
// [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]
// [false,false,true,false,false,true,false]
// 7
// [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]
// [false,false,false,false,false,false,false]
// 4
// [[0,1],[1,2],[0,3]]
// [true,true,true,true]
// 6
// [[0,1],[0,2],[1,3],[3,4],[4,5]]
// [false,true,false,false,true,true]

//             0
//         1*       2
//     3 
// 4*   
//     5*


// WA
// class Solution {
// public:
//     int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
//         unordered_map<int,int> m;
//         int ans=0;
//         set<int> parent;
//         map<int,int> parentCnt;
//         for(int i=0;i<edges.size();i++){
//             int a=edges[i][0], b=edges[i][1];
//             m[b]+=2;
            
//             if(!hasApple[b]) continue;
//             ans+=m[b];
//             parentCnt[a]++;
//             if(parentCnt[a]>=2) parent.insert(a);
//         }
        
//         if(!hasApple[0]){
//              for(auto it=parent.begin();it!=parent.end();it++){
//                 ans+=m[*it];
//             }
//         }
       
//         return ans;
//     }
// };