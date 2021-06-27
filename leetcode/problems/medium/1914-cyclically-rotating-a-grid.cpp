/*
Cyclically Rotating a Grid
https://leetcode.com/problems/cyclically-rotating-a-grid/

You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.

The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:

A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:


Return the matrix after applying k cyclic rotations to it. 

Example 1:


Input: grid = [[40,10],[30,20]], k = 1
Output: [[10,20],[40,30]]
Explanation: The figures above represent the grid at every state.

Example 2:
  
Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
Explanation: The figures above represent the grid at every state.
 
Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 50
Both m and n are even integers.
1 <= grid[i][j] <= 5000
1 <= k <= 109
*/

class Solution {
public:
    int a[200], shifted[200];
    void rotate(vector<vector<int>>& grid, int m_start, int m_end, int n_start, int n_end, int k) {
        if(m_start>m_end || n_start > n_end) return;
        // 1. prepare 1D array
        int cnt = 0;
        // top left -> top right
        for(int i = m_start; i <= m_end; i++) a[cnt++] = grid[n_start][i];
        // top right -> bottom right
        for(int i = n_start + 1; i < n_end; i++) a[cnt++] = grid[i][m_end];
        // bottom right -> bottom left
        for(int i = m_end;  i>= m_start; i--) a[cnt++] = grid[n_end][i];
        // bottom left -> top left
        for(int i = n_end - 1; i > n_start; i--) a[cnt++] = grid[i][m_start];
        // 2. shifting on 1D array
        int shift = k % cnt;
        for(int i = 0; i < cnt; i++) shifted[i] = a[(i + shift) % cnt];
        // 3. convert 1D shifted array to 2D array
        cnt = 0;
        for(int i = m_start; i <= m_end; i++) grid[n_start][i] = shifted[cnt++];
        for(int i = n_start + 1; i < n_end; i++) grid[i][m_end] = shifted[cnt++];
        for(int i = m_end; i >= m_start; i--) grid[n_end][i] = shifted[cnt++];
        for(int i = n_end - 1; i > n_start; i--) grid[i][m_start] = shifted[cnt++];
        // 4. move to next layer
        rotate(grid, m_start + 1, m_end - 1, n_start + 1, n_end - 1, k);
    }
    
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        rotate(grid, 0, m - 1, 0, n - 1, k);
        return grid;
    }
};