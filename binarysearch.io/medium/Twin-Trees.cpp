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
    bool solve(Tree* root0, Tree* root1) {
        if(!root0&&!root1) return true;
        if(!root0||!root1) return false;
        if(root0->val!=root1->val) return false;
        return solve(root0->left,root1->left)&&solve(root0->right,root1->right);
    }
};
