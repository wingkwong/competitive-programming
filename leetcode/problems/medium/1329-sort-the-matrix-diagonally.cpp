/*
Sort the Matrix Diagonally
https://leetcode.com/problems/sort-the-matrix-diagonally/

A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.

 

Example 1:


Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100
*/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = (int) mat.size(), m = (int) mat[0].size();
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mp[i - j].push(mat[i][j]);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mat[i][j] = mp[i - j].top();
                mp[i - j].pop();
            }
        }
        return mat;
    }
};