#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<vector<int>> solve(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        unordered_map<int,int> r,c;
        int m=matrix.size();
        if(m==0) return matrix;
        int n=matrix[0].size();
        if(n==0) return matrix;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    r[i]=1, c[j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(r[i]||c[j]){
                    matrix[i][j]=0;
                }
            }
        }
        return matrix;
    }
};
