/*
Number of Distinct Islands
https://leetcode.com/problems/number-of-distinct-islands/

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Example 1:
11000
11000
00011
00011
Given the above grid map, return 1.
Example 2:
11011
10000
00001
11011
Given the above grid map, return 3.

Notice that:
11
1
and
 1
11
are considered different island shapes, because we do not consider reflection / rotation.
Note: The length of each dimension in the given grid does not exceed 50.
*/

class Solution {
public:
    string dfs(vector<vector<int>>& matrix, int i, int j, string path) {
      if (i < 0 || i > matrix.size() - 1 || j < 0 || j > matrix[0].size() - 1 || matrix[i][j] != 1) return "#";
      matrix[i][j] = 0;
      return path + 
             dfs(matrix, i + 1, j, "D") +
             dfs(matrix, i - 1, j, "U") +
             dfs(matrix, i, j + 1, "R") +  
             dfs(matrix, i, j - 1, "L");
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        set<string> seen;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    string path = dfs(grid, i, j, "");
                    seen.insert(path);
                }
            }
        }
        return (int) seen.size();
    }
};