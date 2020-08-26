/*
Binary Tree Inorder Traversal

Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
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


// in-order dfs
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
private:
    vector<int> ans;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }
};


// stack approach 
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode* cur=root;
        while(cur||!s.empty()){
            // traverse each node till no further left node
            while(cur){
                s.push(cur);
                cur=cur->left;
            }
            // cur is null at this moment, get one from the stack
            cur=s.top();
            // pop it
            s.pop();
            // add it to vector
            ans.push_back(cur->val);
            // traverse the right node
            cur=cur->right;
        }
        return ans;
    }
};