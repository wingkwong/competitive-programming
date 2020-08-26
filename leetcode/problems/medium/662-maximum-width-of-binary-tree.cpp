/*
Maximum Width of Binary Tree
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.
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
    int widthOfBinaryTree(TreeNode* root) {
        vector<unsigned long long> s;
        // approach: dfs. don't need to care about the value
        dfs(root,0,1LL,s);
        return ans;
    }
private:
    long long ans=1;    
    // use unsigned long long to avoid overflow
    void dfs(TreeNode* root, unsigned long long lv, unsigned long long idx, vector<unsigned long long>& s){
        if(!root) return;
        if(s.size()==lv) s.emplace_back(idx); // storing the leftmost node idx
        else if(idx-s[lv]+1>ans) ans=idx-s[lv]+1; // 
        dfs(root->left,lv+1,idx*2,s);  // the next left node would be idx*2
        dfs(root->right,lv+1,idx*2+1,s); // the next left node would be idx*2+1
    }
};

//            1
//        /       \  
//      2         3  
//     /  \        /  \
//   4    5        6   7