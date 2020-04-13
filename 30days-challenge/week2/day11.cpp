/*
Diameter of Binary Tree

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // base case where tree is empty
        if(root==NULL) return 0;
        // get the height of left and right sub-trees
        int lheight=height(root->left);
        int rheight=height(root->right);
        // get the diameter of left and right sub-trees
        int ldiameter=diameterOfBinaryTree(root->left);
        int rdiameter=diameterOfBinaryTree(root->right);
        // Return max of following three 
        //  1) Diameter of left subtree 
        //  2) Diameter of right subtree 
        //  3) Height of left subtree + height of right subtree
        return max(lheight+rheight, max(ldiameter,rdiameter));
        // return max(lheight+rheight+1, max(ldiameter,rdiameter));
    }
    
    int height(TreeNode* node){
        // base case where tree is empty
        if(node==NULL) return 0;
        // If tree is not empty then height = 1 + max of left  
        // height and right heights
        return 1+max(height(node->left), height(node->right));
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();