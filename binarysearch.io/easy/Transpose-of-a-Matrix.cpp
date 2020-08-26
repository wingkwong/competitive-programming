#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<vector<int>> solve(vector<vector<int>>& matrix) {
        vector<vector<int>> ans = matrix;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                ans[j][i] = matrix[i][j];
            }
        }
        
        return ans;
    }
};
