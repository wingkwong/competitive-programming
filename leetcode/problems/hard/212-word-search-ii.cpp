/*
Word Search II


Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word. 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 

Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/

class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        string word;
        TrieNode():word(""){
            for(int i=0;i<26;i++) {
                children[i] = nullptr;
            }
        }
    };
    
    TrieNode* buildTrie(vector<string>& words){
        TrieNode* root = new TrieNode();
        for(string word:words){
            TrieNode *cur = root;
            for(char c:word){
                if(cur->children[c-'a']==nullptr){
                    cur->children[c-'a']=new TrieNode();
                }
                cur = cur->children[c-'a'];
            }
            cur->word = word;
        }
        return root;
    }
    
    void dfs(int i, int j, vector<vector<char>>& board, TrieNode* root, vector<string>& ans){
        char c=board[i][j];
        // if visited or no such character, return 
        if(c=='*'||!root->children[c-'a']) return;
        root = root->children[c-'a'];
        if(root->word.size()){
            // add it to ans    
            ans.push_back(root->word);
            // de-duplicate from trie node
            root->word="";
        }
        // set it to other character. consider it has been visited
        board[i][j]='*';
        // dfs - 4 directions
        if(i>0) dfs(i-1,j,board,root,ans);
        if(j>0) dfs(i,j-1,board,root,ans);
        if(i<board.size()-1) dfs(i+1,j,board,root,ans);
        if(j<board[0].size()-1) dfs(i,j+1,board,root,ans);
        // backtracking
        board[i][j]=c;
    }
        
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // approach: trie + dfs + backtracking
        // build trie node 
        TrieNode* root = buildTrie(words);
        vector<string> ans;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                // dfs
                dfs(i,j,board,root,ans);
            }
        }
        return ans;
    }
};