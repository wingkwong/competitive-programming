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
    int dfs(Tree* root){
        if (!root) return INT_MIN;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if (root->val >= max(l, r))  ans++;
        return max({l, r, root->val});
    }
    int solve(Tree* root) {
        dfs(root);
        return ans;
    }
};
