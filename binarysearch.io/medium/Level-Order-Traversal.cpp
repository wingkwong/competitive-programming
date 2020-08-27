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
    vector<int> solve(Tree* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<Tree*> q;
        q.push(root);
        while(!q.empty()){
            Tree* node = q.front();
            q.pop();
            ans.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return ans;
    }
};
