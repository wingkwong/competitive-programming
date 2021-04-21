/*
Surface Area of 3D Shapes
https://leetcode.com/problems/surface-area-of-3d-shapes/

You are given an n x n grid where you have placed some 1 x 1 x 1 cubes. Each value v = grid[i][j] represents a tower of v cubes placed on top of cell (i, j).

After placing these cubes, you have decided to glue any directly adjacent cubes to each other, forming several irregular 3D shapes.

Return the total surface area of the resulting shapes.

Note: The bottom face of each shape counts toward its surface area.

 

Example 1:


Input: grid = [[2]]
Output: 10
Example 2:


Input: grid = [[1,2],[3,4]]
Output: 34
Example 3:


Input: grid = [[1,0],[0,2]]
Output: 16
Example 4:


Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 32
Example 5:


Input: grid = [[2,2,2],[2,1,2],[2,2,2]]
Output: 46
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 50
0 <= grid[i][j] <= 50
*/

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans = 0, n = (int) grid.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
            	// 4 sides + top + bottom
                if(grid[i][j]) ans += 4 * grid[i][j] + 2;
                // minus overlapping area
                if(i) ans -= min(grid[i][j], grid[i - 1][j]) * 2;
                if(j) ans -= min(grid[i][j], grid[i][j - 1]) * 2;
            }
        }
        return ans;
    }
};