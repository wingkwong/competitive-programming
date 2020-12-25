/*
Diagonal Traverse

Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.


Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

Explanation:


Note:

The total number of elements of the given matrix will not exceed 10,000.
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n = (int) matrix.size();
        vector<int> ans;
        if(n == 0) return ans;
        int m = (int) matrix[0].size();
        vector<vector<int>> d(n * m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                d[i + j].push_back(matrix[i][j]);
            }
        }
        for(int i = 0; i < d.size(); i++) {
            if((i & 1) ^ 1) {
                ans.insert(ans.end(), d[i].rbegin(), d[i].rend());
            } else {
                ans.insert(ans.end(), d[i].begin(), d[i].end());
            }
        }
        return ans;
    }
};
