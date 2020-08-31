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
    bool solve(Tree* root, int val) {
        if(!root) return false;
        if(root->val==val) return true;
        return solve(root->left, val)||solve(root->right, val);
    }
};
