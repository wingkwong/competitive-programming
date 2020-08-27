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
    Tree* solve(Tree* root) {
        if(!root) return NULL;
        Tree* node=root;
        Tree* l=solve(root->left);
        Tree* r=solve(root->right);
        node->left=r;node->right=l;
        return root;
    }
};
