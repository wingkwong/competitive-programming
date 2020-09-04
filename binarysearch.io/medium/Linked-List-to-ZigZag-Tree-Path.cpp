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
/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
class Solution {
    public:
    Tree* solve(LLNode* node) {
        if(!node) return NULL;
        Tree* root = new Tree(node->val);
        if(node->next) {
            if(node->next->val<node->val) root->left = solve(node->next);
            else root->right = solve(node->next);
        }
        return root;
    }
};
