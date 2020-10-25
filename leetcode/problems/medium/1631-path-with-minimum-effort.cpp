/*
Path With Minimum Effort
https://leetcode.com/problems/path-with-minimum-effort/

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
 

Constraints:

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106
*/

// AC - binary search + dfs
class Solution {
public:
    int dirx[4]={ -1, 0, 0, 1 };
    int diry[4]={ 0, 1, -1, 0 };
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& vis, int i, int j, int mid) {
        vis[i][j] = 1;
        for(int d = 0; d < 4; d++) {
            int x = i + dirx[d], y = j + diry[d];
            if(x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size() || vis[x][y]) continue;
            if(abs(heights[i][j] - heights[x][y]) > mid) continue;
            dfs(heights, vis, x, y, mid);
        }
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = (int) heights.size(), n = m ? (int) heights[0].size() : 0;
        int l = 0, r = 1e6;
        while(l < r) {
            int mid = l + (r - l) / 2;
            vector<vector<int>> vis(m, vector<int>(n, 0));
            dfs(heights, vis, 0, 0, mid);
            if(vis[m - 1][n - 1]) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

// Contest Solution - TLE
class Solution {
public:
    vector<int> path;
    vector<int> ans;
    int t;
    
    bool ok(int i, int j, vector<vector<int>>& vis){
        return i>=0&&i<(int)vis[0].size()&&j>=0&&j<(int)vis[0].size()&&!vis[i][j];
    }
    void go(vector<vector<int>>& heights, vector<vector<int>>& vis, int i, int j, vector<int> path = {}) {
        if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || vis[i][j] == 1)  return; 
        if (i == heights.size() - 1 && j == heights[0].size() - 1) { 
            path.push_back(heights[i][j]); 
            t = 0;
            for (int k = 1; k < path.size(); k++) {
                int a = abs(path[k] - path[k - 1]);
                t = max(t, a);
                // cout << path[k] << " ";
            }
            ans.push_back(t);
            // cout << " ::: " << t << " "<< "\n";
            return; 
        } 
        vis[i][j] = 1; 
        path.push_back(heights[i][j]); 
        if(j < heights[0].size() - 1 && !vis[i][j + 1]) {
            if(!(!ok(i, j + 2, vis)&&ok(i - 1, j + 1, vis)&&ok(i + 1, j + 1, vis))){
                go(heights, vis, i, j + 1, path); 
            }
        }
        if(i < heights.size() - 1 && !vis[i + 1][j]) {
            if(!(!ok(i + 2, j, vis)&&ok(i + 1, j - 1, vis)&&ok(i + 1, j + 1, vis))) {
                go(heights, vis, i + 1, j, path); 
            }
        }
        if(i > 0 && !vis[i - 1][j]) {
            if(!(!ok(i - 2, j, vis)&&ok(i - 1, j - 1, vis)&&ok(i - 1, j + 1, vis))) {
                go(heights, vis, i - 1, j, path); 
            }
        }
        if(j > 0 && !vis[i][j - 1]) {
            if(!(!ok(i, j - 2, vis)&&ok(i - 1, j - 1, vis)&&ok(i + 1, j - 1, vis))){
                go(heights, vis, i, j - 1, path); 
            }
        }
        path.pop_back(); 
        vis[i][j] = 0; 
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = (int) heights.size(), n = (int) heights[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        go(heights, vis, 0, 0);
        return *min_element(ans.begin(), ans.end());
    }
};