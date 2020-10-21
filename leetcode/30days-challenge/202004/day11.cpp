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

// O(n)
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int h;
        return diameter(root,&h);
    }
    
    int diameter(TreeNode* root, int* h){
        // lh --> Height of left subtree 
        // rh --> Height of right subtree
        // ldiameter  --> diameter of left subtree 
        // rdiameter  --> Diameter of right subtree
        int lh=0,rh=0,ld=0,rd=0;
        // base case tree is empty
        if(root==NULL){
            *h=0;
            return 0;
        }
        // Get the heights of left and right subtrees in lh and rh 
        // And store the returned values in ldiameter and ldiameter
        ld=diameter(root->left, &lh);
        rd=diameter(root->right, &rh);
        // Height of current node is max of heights of left and 
        // right subtrees plus one
        *h=max(lh,rh)+1;
        return max(lh+rh, max(ld,rd));;
        // return max(lh+rh+1, max(ld,rd));
    }
};

// O(n^2)
class Solution2 {
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

// DFS
class Solution3 {
public:
    int ans;
    int dfs(TreeNode* node) {
        if(node == NULL) return 0;
        int l = dfs(node->left);
        int r = dfs(node->right);
        ans = max(ans, l+r+1);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        dfs(root);
        return ans - 1;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();