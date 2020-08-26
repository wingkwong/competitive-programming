/*
Binary Tree Maximum Path Sum

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
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
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
private:
    int ans=INT_MIN;
    int helper(TreeNode* root){
        // base case
        if(!root) return 0;
        // l and r store max path sum going thru left and right child of root 
        int l = helper(root->left);
        int r = helper(root->right);
        // max path for parent call of root
        // include at most 1 child of root
        int max_single = max(root->val, root->val+max(l,r));
        // the maxsum path of the node
        int max_top = max(max_single,root->val+l+r);
        // store the max result
        ans=max(ans,max_top);
        return max_single;
    }
};

class Solution2 {
public:
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
private:
    int ans=INT_MIN;
    int helper(TreeNode* root){
        if(!root) return 0;
        int l=max(0,helper(root->left));
        int r=max(0,helper(root->right));
        ans=max(ans,l+root->val+r);
        return max(l,r) + root->val;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();