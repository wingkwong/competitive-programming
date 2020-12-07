/*
Spiral Matrix II
https://leetcode.com/problems/spiral-matrix-ii/

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]

Constraints:

1 <= n <= 20
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n, 1));
        int left, right, top, down, index;
        left = top = index = 0, right = down = n - 1;
        while (left <= right && top <= down) {
            for (int j = left; j <= right; j++) ans[top][j] = ++index;
            top++;
            for (int i = top; i <= down; i++) ans[i][right] = ++index;
            right--;
            for (int j = right; j >= left; j--) ans[down][j] = ++index;
            down--;
            for (int i = down; i >= top; i--) ans[i][left] = ++index;
            left++;
        }
        return ans;
    }
};