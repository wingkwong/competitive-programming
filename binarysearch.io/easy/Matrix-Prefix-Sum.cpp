#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<vector<int>> solve(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0) return matrix;
        int n = matrix[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(i==0&&j==0) continue;
                else if(i==0) matrix[i][j]+=matrix[i][j-1];
                else if(j==0) matrix[i][j]+=matrix[i-1][j];
                else matrix[i][j]+=matrix[i][j-1]+matrix[i-1][j]-matrix[i-1][j-1];
        
        return matrix;
    }
};
