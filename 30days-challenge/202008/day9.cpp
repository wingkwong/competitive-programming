/*
Rotting Oranges
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

Example 1:

Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.

*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt=0, ans=-1;
        queue<vector<int>> q;
        // count each orange and put rotted oranges to a queue
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]>0) cnt++;
                if(grid[i][j]==2) {
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        // bfs approach to rot the adjacent orange
        while(!q.empty()){
            ans++;
            int n = q.size();
            for(int i=0;i<n;i++){
                vector<int> c=q.front();
                q.pop();
                cnt--;
                // check 4 directions
                for(int j=0;j<4;j++){
                    int x=c[0]+dir[j][0], y=c[1]+dir[j][1];
                    if(x>=grid.size()||x<0||y>=grid[0].size()||y<0||grid[x][y]!=1) continue;
                    grid[x][y]=2;
                    q.push({x,y});
                }
            }
        }
        // if all oranges are rotted, return max(ans,0) 
        if(cnt==0) return max(ans,0);
        // if not, return -1
        return -1;
    }
}