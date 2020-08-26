/*
Regions Cut By Slashes

In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into contiguous regions.

(Note that backslash characters are escaped, so a \ is represented as "\\".)

Return the number of regions.

 

Example 1:

Input:
[
  " /",
  "/ "
]
Output: 2
Explanation: The 2x2 grid is as follows:

Example 2:

Input:
[
  " /",
  "  "
]
Output: 1
Explanation: The 2x2 grid is as follows:

Example 3:

Input:
[
  "\\/",
  "/\\"
]
Output: 4
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
The 2x2 grid is as follows:

Example 4:

Input:
[
  "/\\",
  "\\/"
]
Output: 5
Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
The 2x2 grid is as follows:

Example 5:

Input:
[
  "//",
  "/ "
]
Output: 3
Explanation: The 2x2 grid is as follows:


Note:

1 <= grid.length == grid[0].length <= 30
grid[i][j] is either '/', '\', or ' '.
*/

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int sz=(int)grid.size();
        int ans=0;
        vector<vector<int>> g(sz*3,vector<int>(sz*3,0));
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                // expand the grid 3 times, set edges to 1
                // if you expand it 2 times, the gap is not wide enough for dfs
                if(grid[i][j]=='/') g[i*3][j*3+2]=g[i*3+1][j*3+1]=g[i*3+2][j*3]=1;
                if(grid[i][j]=='\\') g[i*3][j*3]=g[i*3+1][j*3+1]=g[i*3+2][j*3+2]=1;
            }
        }
        int gsz=(int)g.size();
        // perform dfs, search for 0 and fill with 1
        for(int i=0;i<gsz;i++){
            for(int j=0;j<gsz;j++){
                if(!g[i][j]) {
                    dfs(i,j,g);
                    ans++;
                }
            }
        }
        return ans;
    }
private:
    void dfs(int i, int j, vector<vector<int>>&g){
        int sz=(int)g.size();
        // return if it s out of bound or it is visited / edges
        if(i<0||i>=sz||j>=sz||j<0||g[i][j]) return;
        // fill the grid with 1 
        g[i][j]=1;
        // perform for 4 directions
        dfs(i+1,j,g);
        dfs(i-1,j,g);
        dfs(i,j+1,g);
        dfs(i,j-1,g);
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();