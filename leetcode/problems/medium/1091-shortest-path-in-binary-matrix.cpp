/*
Shortest Path in Binary Matrix
https://leetcode.com/problems/shortest-path-in-binary-matrix/

In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.

 

Example 1:

Input: [[0,1],[1,0]]


Output: 2

Example 2:

Input: [[0,0,0],[1,1,0],[1,1,0]]


Output: 4

 

Note:

1 <= grid.length == grid[0].length <= 100
grid[r][c] is 0 or 1
*/

class Solution {
public:
    int dirx[8]={ -1, 0, 0, 1, -1, -1, 1, 1 };
    int diry[8]={ 0, 1, -1, 0, -1, 1, -1, 1 };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    	// bfs
        int n = (int) grid.size();
        if(grid[0][0] == 1) return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int ans = 0;
        while(!q.empty()) {
            int t = (int) q.size();
            ans++;
            while(t--) {
                auto [i, j] = q.front();
                q.pop();
                if(i == n - 1 && j == n - 1) return ans;
                for(int d = 0; d < 8; d++) {
                    int ni = i + dirx[d];
                    int nj = j + diry[d];
                    if(ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 0) {
                        grid[ni][nj] = 1;
                        q.push({ni, nj});
                    }
                }
            }
        }
        return -1;
    }
};