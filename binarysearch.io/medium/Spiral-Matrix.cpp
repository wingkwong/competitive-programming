#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<int> ans;
    void solve(vector<vector<int>>& matrix, int i, int j, int m, int n){
        // If i or j is out of bound, return it. Then print the first row and the last column. 
        // If the last and the first row are different, print the last row. 
        // Similarly, if the last and first column are different, print the first column. Repeat it till i>=m and j>=n.
        if (i>=m||j>=n)  return; 
        for(int k=i; k<n; k++)  ans.push_back(matrix[i][k]);
        for(int k=i+1; k<m; k++) ans.push_back(matrix[k][n-1]);
        if (m-1!=i) for(int k=n-2; k>=j; k--) ans.push_back(matrix[m-1][k]);
        if (n-1!=j) for(int k=m-2; k>i; k--) ans.push_back(matrix[k][j]); 
        solve(matrix,i+1,j+1,m-1,n-1); 
    }
    vector<int> solve(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        solve(matrix,0,0,m,n);
        return ans;
    }
};
