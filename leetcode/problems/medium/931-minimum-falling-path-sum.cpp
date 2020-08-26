/*
Minimum Falling Path Sum

Given a square array of integers A, we want the minimum sum of a falling path through A.

A falling path starts at any element in the first row, and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.

 

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12
Explanation: 
The possible falling paths are:
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
The falling path with the smallest sum is [1,4,7], so the answer is 12.

Note:

1 <= A.length == A[0].length <= 100
-100 <= A[i][j] <= 100
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int sz = (int)A.size();
        // starting from row 1 
        for(int i=1;i<sz;i++){
            // update each A[i][j] - take the minimum sum from the top left, top, top right value
            for(int j=0;j<sz;j++){
                A[i][j] += min({
                   A[i-1][max(j-1,0)], // top left
                   A[i-1][j], // top 
                   A[i-1][min(j+1,sz-1)], // top right 
                });
            }
        }
        // the ans is the min value of the last row
        return *min_element(A[sz-1].begin(), A[sz-1].end());
    }
};

// 1 2 3
// 4 5 6 -> 5  6  8
// 7 8 9    12 13 15

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();