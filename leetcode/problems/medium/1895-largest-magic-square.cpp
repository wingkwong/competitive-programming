/*
Largest Magic Square
https://leetcode.com/problems/largest-magic-square/

A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal. The integers in the magic square do not have to be distinct. Every 1 x 1 grid is trivially a magic square.

Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square that can be found within this grid.

 

Example 1:


Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
Output: 3
Explanation: The largest magic square has a size of 3.
Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
- Diagonal sums: 5+4+3 = 6+4+2 = 12
Example 2:


Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
Output: 2
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j] <= 106
*/

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<int>> rows(m + 2, vector<int>(n + 2)), cols(rows), d1(rows), d2(rows);
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++) {
                rows[i][j] += grid[i - 1][j - 1] + rows[i][j - 1];
                cols[i][j] += grid[i - 1][j - 1] + cols[i - 1][j];
                d1[i][j] += grid[i - 1][j - 1] + d1[i - 1][j - 1];
                d2[i][j] += grid[i - 1][j - 1] + d2[i - 1][j + 1];
            }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                for(int k = min(m - i, n - j); k > ans; k--) {
                    int sum = d1[i + k][j + k] - d1[i - 1][j - 1];
                    bool match = sum == d2[i + k][j] - d2[i - 1][j + k + 1]; 
                    for(int l = 0; l <= k && match; l++) {
                        match &= sum == rows[i + l][j + k] - rows[i + l][j - 1];
                        match &= sum == cols[i + k][j + l] - cols[i - 1][j + l];
                    }
                    if (match) {
                        ans = k;
                        break;
                    }
                }
            }
        }
        return ans + 1;
    }
};