/*
Largest-Island-Area
https://binarysearch.io/problems/Largest-Island-Area

You are given a two-dimensional integer matrix of 1s and 0s. A 1 represents land and 0 represents water, so an island is a group of 1s that are neighboring whose perimeter is surrounded by water. You can assume that the edges of the matrix are surrounded by water.

Return the area of the largest island in matrix.

Constraints

n, m ≤ 250 where n and m are the number of rows and columns in matrix
Example 1
Input

matrix = [
    [0, 0, 0, 1, 1, 1, 1],
    [0, 0, 0, 0, 0, 0, 0],
    [0, 1, 1, 1, 1, 1, 0],
    [0, 0, 1, 1, 0, 0, 0],
    [0, 0, 0, 0, 0, 1, 1],
    [0, 0, 0, 0, 0, 0, 0]
]
Output

7
Explanation

The largest island in the center has an area of 7 units.
*/

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int dfs(vector<vector<int>>& matrix, int i, int j){
        if(i<0||i>matrix.size()-1||j<0||j>matrix[0].size()-1||matrix[i][j]==0) return 0;
        matrix[i][j]=0;
        return 1 + dfs(matrix,i+1,j)+ dfs(matrix,i-1,j) + dfs(matrix,i,j+1) + dfs(matrix,i,j-1);
    }
    int solve(vector<vector<int>>& matrix) {
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==1){
                    ans=max(ans,dfs(matrix,i,j));
                }
            }
        }
        return ans;
    }
};
