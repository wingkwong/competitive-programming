/*
Surrounded Regions
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/

class Solution {
public:
    // X X X X        X X X X         X X X X
    // X O O X        X O O X         X X X X
    // X X O X        X X O X         X X X X
    // X O X X        X 1 X X         X O X X
    void dfs(int i, int j, int m, int n, vector<vector<char>>& board){
        if (board[i][j]=='O') {
            board[i][j]='1';
            if (i>1) dfs(i-1,j,m,n,board);
            if (j>1) dfs(i,j-1,m,n,board);
            if (i+1<m) dfs(i+1,j,m,n,board);
            if (j+1<n) dfs(i,j+1,m,n,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(); if(m==0) return;
        int n=board[0].size();
        
        for(int i=0;i<m;i++){
            dfs(i,0,m,n,board);
            dfs(i,n-1,m,n,board);
        }
        
        for(int j=0;j<n;j++){
            dfs(0,j,m,n,board);
            dfs(m-1,j,m,n,board);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='1') board[i][j]='O';
            }
        }
    }
};

// [["X","X","X","X"],
//  ["X","O","O","X"],
//  ["X","X","O","X"],
//  ["X","O","X","X"]]
 
// [["X","X","X","X"],
//  ["X","X","O","X"],
//  ["X","X","O","X"],
//  ["X","O","X","X"]]