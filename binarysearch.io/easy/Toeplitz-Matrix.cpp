#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int m, n;
    bool ok(vector<vector<int>>& matrix, int i, int j){
        int val = matrix[i][j];
        while(++i<m&&++j<n){
            if(matrix[i][j]!=val){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        for(int i=0;i<m;i++){
            if(!ok(matrix,i,0)) return false;
        }
        for(int i=1;i<n;i++){
            if(!ok(matrix,0,i)) return false;
        }
        return true;
    }
};
