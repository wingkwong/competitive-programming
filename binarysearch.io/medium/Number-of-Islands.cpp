#include "solution.hpp"
using namespace std;


class Solution {
    public:
    void dfs(vector<vector<int>>& matrix, int i, int j){
        if(i<0||i>matrix.size()-1||j<0||j>matrix[0].size()-1||matrix[i][j]==0) return;
        matrix[i][j]=0;
        dfs(matrix,i+1,j);
        dfs(matrix,i,j+1);
        dfs(matrix,i-1,j);
        dfs(matrix,i,j-1);
    }
    int solve(vector<vector<int>>& matrix) {
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==1){
                    dfs(matrix,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
