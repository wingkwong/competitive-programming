/*
01 Matrix

Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]
 

Note:

The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
*/

class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int i, int j){
        if(i<0||i>matrix.size()-1||j<0||j>matrix[0].size()-1||matrix[i][j]==-1) return 10000;
        if(matrix[i][j]==0||matrix[i][j]==1) {
            return matrix[i][j];
        }
        int d = matrix[i][j];
        // -1 : visited
        matrix[i][j]=-1;
        d = min({
            d,
            dfs(matrix,i+1,j)+1,
            dfs(matrix,i-1,j)+1,
            dfs(matrix,i,j+1)+1,
            dfs(matrix,i,j-1)+1
        });
        // inplace update
        matrix[i][j]=d;
        return  d;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        // approach: dfs inplace 
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                // The number of elements of the given matrix will not exceed 10,000.
               if(matrix[i][j]==1) matrix[i][j]=10000;
            }
        }
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                dfs(matrix,i,j);
            }
        }
        return matrix;
    }
};