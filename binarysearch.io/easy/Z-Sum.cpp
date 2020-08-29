#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(vector<vector<int>>& matrix) {
        int m=matrix.size(), ans=0;
        if(m==0) return ans;
        int n=matrix[0].size();
        for(int i=0;i<n;i++) ans+=matrix[0][i];
        for(int i=1,j=n-2;i<=m-2&&j>=1;i++,j--) ans+=matrix[i][j];
        for(int i=0;i<n&&m>1;i++) ans+=matrix[m-1][i];
        return ans;
    }
};
