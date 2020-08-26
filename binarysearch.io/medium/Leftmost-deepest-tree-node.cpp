#include "solution.hpp"
using namespace std;

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
class Solution {
    public:
    int ans, mxLevel=-1;
    void dfs(Tree* root, int level){
        if(!root) return;
        if(!root->left&&!root->right&&level>mxLevel){
            ans=root->val;
            mxLevel=level;
        }
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    int solve(Tree* root) {
        dfs(root,0);
        return ans;
    }
};
