/*
Count Square Submatrices with All Ones
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]&&i&&j){
                    // check the size of biggest square with A[i][j] as bottom-right corner
                    // if matrix[i][j]=0, that means it s not a valid sqaure
                    matrix[i][j]=min({matrix[i-1][j-1],matrix[i-1][j],matrix[i][j-1]})+1;
                }
                ans+=matrix[i][j];
            }
        }
        return ans;
    }
};