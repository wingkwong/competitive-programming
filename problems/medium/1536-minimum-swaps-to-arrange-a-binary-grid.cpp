/*
Minimum Swaps to Arrange a Binary Grid

Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.

A grid is said to be valid if all the cells above the main diagonal are zeros.

Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.

The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).

Example 1:


Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
Output: 3

Example 2:

Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
Output: -1
Explanation: All rows are similar, swaps have no effect on the grid.

Example 3:
Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
Output: 0
 
Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 200
grid[i][j] is 0 or 1
*/

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        // find the min swaps to convert the tailing zeros in a descending order 
        // [0,1,2] --> [2,1,0]
        int n = grid.size(), ans=0;
        vector<int> v(n,0);
        // calculate how many tailing zeros for each row
        // e.g. [[0,0,1],[1,1,0],[1,0,0]] --> [0,1,2]
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0) v[i]++;
                else break;
            }
        }
        for(int i=0;i<n;i++){
            int j=i;
            // look for the first candidate to swap
            while(j<n&&v[j]<n-1-i) j++;
            // swaps have no effect on the grid, return -1
            if(j==n) return -1;
            int jj=j;
            // swap two adjacent rows
            while(jj>i){
                swap(v[jj],v[jj-1]);
                jj--;
                ans++;
            }
        }
        return ans;
    }
};