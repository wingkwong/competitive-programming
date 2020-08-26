/*
Maximum Depth of Binary Tree

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
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


// Bottom-up Solution
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        // calcuate left node depth
        int l = maxDepth(root->left);
        // calcuate right node depth
        int r = maxDepth(root->right);
        // get the maximum depth plus 1 (root)
        return max(l,r) + 1;
    }
};

// Top-down Solution
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return ans;
        calculateDepth(root,1);
        return ans;
    }
private:
    int ans=0;
    void calculateDepth(TreeNode* root, int depth){
        if(!root) return;
        // update the ans if we see a higher depth
        ans=max(ans,depth);
        // calcuate left node depth
        calculateDepth(root->left,depth+1);
        // calcuate right node depth
        calculateDepth(root->right, depth+1);
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();