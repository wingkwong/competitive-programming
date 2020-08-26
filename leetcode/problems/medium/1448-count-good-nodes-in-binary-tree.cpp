/*
Count Good Nodes in Binary Tree

Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.
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
    void dsf(TreeNode* root, int val){
        // if root is NULL, return
        if(!root) return;
        // if the node value is greater than / equal to the max value, increase ans by 1
        if(root->val>=val) ans++;
        int mx=max(root->val,val);
        // pass the max value to left node
        dsf(root->left, mx);
        // pass the max value to right node
        dsf(root->right, mx);
    }
    
    int goodNodes(TreeNode* root) {
        // simple dsf approach
        // record the maximum value along the path from the root to the node
        dsf(root, root->val); 
        return ans;
    }
private:
    int ans=0;
};