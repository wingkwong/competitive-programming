#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int ans=INT_MAX, m,n;
    int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};
    bool ok(int i, int j){
        return !(i<0||i>m-1||j<0||j>n-1);
    }
    int solve(vector<vector<int>>& matrix) {
        m=matrix.size(), n=matrix[0].size();
        if(matrix[0][0]==1||matrix[m-1][n-1]==1) return -1;
        queue<pair<pair<int,int>,int>> q; // i,j,cnt
        q.push({{0,0},1});
        matrix[0][0]=1;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int x=p.first.first, y=p.first.second, cnt=p.second;
            if(x==m-1&&y==n-1) ans=min(ans,cnt);
            for(int i=0;i<4;i++){
                int xx=x+dx[i], yy=y+dy[i];
                if(ok(xx,yy)&&matrix[xx][yy]==0){
                    matrix[xx][yy]=1;
                    q.push({{xx,yy},cnt+1});
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
