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
    int solve(Tree* root, vector<string>& moves) {
        vector<string> v;
        for(string s:moves){
            if(s=="UP") v.pop_back();
            else v.push_back(s);
        }
        for(string s:v){
            if(s=="LEFT") root=root->left;
            else root=root->right;
        }
        return root->val;
    }
};
