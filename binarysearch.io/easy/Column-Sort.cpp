/*
Column-Sort
https://binarysearch.io/problems/Column-Sort

Given a two-dimensional integer matrix, sort each of the columns in ascending order.

Example 1
Input

matrix = [
    [10, 20, 30],
    [5, 5, 3],
    [0, 10, 7]
]
Output

[
    [0, 5, 3],
    [5, 10, 7],
    [10, 20, 30]
]
*/

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<vector<int>> solve(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<int> cols;
        vector<vector<int>> ans = matrix;
        // extract each column, sort it in ascending order
        // put it back to the right place
        for(int col=0;col<n;col++){
            for(int row=0;row<m;row++) cols.push_back(matrix[row][col]);
            sort(cols.begin(), cols.end());
            for(int row=0;row<m;row++) ans[row][col]=cols[row];
            cols.clear();
        }
        return ans;
    }
};
