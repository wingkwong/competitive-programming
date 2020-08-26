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
    int ans=0;
    void dfs(Tree* root){
        if(!root) return;
        ans+=root->val;
        dfs(root->left);
        dfs(root->right);
    }
    int solve(Tree* root) {
        dfs(root);
        return ans;
    }
};
