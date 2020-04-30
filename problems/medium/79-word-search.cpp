/*
Word Search

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        r = (int)board.size();
        c = (int)board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                // find the first char
                if(dfs(i,j,board,word,0)) return true;
            }
        }
        return false;
    }
private:
    int r,c;
    // typical dfs approach
    bool dfs(int i, int j, vector<vector<char>>& board, string& word, int k){
        // base cases
        if(i<0||i>=r||j<0||j>=c||board[i][j]!=word[k]) return false;
        // ans found
        if(k==word.size()-1) return true;
        // mark board[i][j] to '*' to represent this char has been visited
        char cur = board[i][j];
        board[i][j] = '*';
        // search for four directions
        bool found = dfs(i-1,j,board,word,k+1)
                    || dfs(i+1,j,board,word,k+1)
                    || dfs(i,j-1,board,word,k+1)
                    || dfs(i,j+1,board,word,k+1);
        // reset. mark it not visited 
        board[i][j] = cur;
        // return if it is found or not
        return found;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();