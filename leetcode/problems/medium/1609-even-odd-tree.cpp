/*
Even Odd Tree
https://leetcode.com/problems/even-odd-tree/

A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

 

Example 1:



Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
Output: true
Explanation: The node values on each level are:
Level 0: [1]
Level 1: [10,4]
Level 2: [3,7,9]
Level 3: [12,8,6,2]
Since levels 0 and 2 are all odd and increasing, and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.
Example 2:



Input: root = [5,4,2,3,3,7]
Output: false
Explanation: The node values on each level are:
Level 0: [5]
Level 1: [4,2]
Level 2: [3,3,7]
Node values in the level 2 must be in strictly increasing order, so the tree is not Even-Odd.
Example 3:



Input: root = [5,9,1,3,5,7]
Output: false
Explanation: Node values in the level 1 should be even integers.
Example 4:

Input: root = [1]
Output: true
Example 5:

Input: root = [11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17]
Output: true
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 106
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

// AC - 424 ms
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> v;
        while(!q.empty()){
            int n = q.size();
            vector<int> cur(n);
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                cur[i]=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            v.push_back(cur);
        }
        for(int i=0;i<v.size();i++){
            if(i&1){
                // all nodes at the level have even integer values 
                // in strictly decreasing order (from left to right)
                for(int j=0;j<v[i].size();j++) {
                    if(v[i][j]&1) return false;
                    if(j) if(v[i][j]>=v[i][j-1]) return false;
                }
            } else {
                // all nodes at the level have odd integer values 
                // in strictly increasing order (from left to right)
                for(int j=0;j<v[i].size();j++) {
                    if((v[i][j]&1)^1) return false;
                    if(j) if(v[i][j]<=v[i][j-1]) return false;
                }
            }
        }
        return true;
    }
};

// simplified Solution 1
// AC - 352 ms
class Solution2 {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int odd = 0;
        while(!q.empty()){
            int n = q.size(), pre = -1;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                int val = node->val;
                if(odd){
                    if(val&1) return false;
                    if(pre!=-1 && val>=pre) return false; 
                } else {
                    if((val&1)^1) return false;
                    if(pre!=-1 && val<=pre) return false; 
                }
                pre=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            odd=!odd;
        }
        return true;
    }
};