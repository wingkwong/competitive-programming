/*
Binary Tree Paths

Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        dfs(root,to_string(root->val), ans);
        return ans;
    }

private:
    void dfs(TreeNode* root, string path, vector<string> &ans){
        // traverse each node and add the answer if no child node is found
        if(!root->left&&!root->right) ans.push_back(path);
        // traverse left node
        if(root->left) dfs(root->left,path+"->"+to_string(root->left->val),ans);
        // traverse right node
        if(root->right) dfs(root->right,path+"->"+to_string(root->right->val),ans);
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();