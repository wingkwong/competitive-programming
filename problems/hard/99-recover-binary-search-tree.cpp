/*
Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
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
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* prev=NULL;
    void solve(TreeNode* node){
        // in-order traversal to search two swapped nodes
        if(!node) return;
        solve(node->left);
        if(prev&&node->val<prev->val){
            if(first==NULL) first=prev;
            second=node;
        }
        prev=node;
        solve(node->right);
    }
    void recoverTree(TreeNode* root) {
        solve(root);
        // swap them back
        swap(first->val, second->val);
    }
};