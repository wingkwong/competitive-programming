/*
Cousins in Binary Tree
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

Example 1:

Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 
Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*,int>> q;
        // {node & parent val}
        q.push({root,0});
        int parent=-1;
        // level order approach
        while(!q.empty()){
            int sz = (int)q.size();
            while(sz--){
                TreeNode* n = q.front().first;
                int p = q.front().second;
                if(n->val==x||n->val==y){
                    // find the target
                    // set the parent if not set
                    if(parent==-1){
                        parent = p;
                    } else {
                        //if set, check if it is same
                        return parent==p? false:true;
                    }
                }
                q.pop();
                // traverse to left branch
                if(n->left) q.push({n->left,n->val});
                // traverse to right branch
                if(n->right) q.push({n->right,n->val});
            }
            // only one target is found, but the other is not at the same level. quit immediately 
            if(parent!=-1) return false;
        }
        return false;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();