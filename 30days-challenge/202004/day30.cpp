/*
Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree

Given a binary tree where each path going from the root to any leaf form a valid sequence, check if a given string is a valid sequence in such binary tree. 

We get the given string from the concatenation of an array of integers arr and the concatenation of all values of the nodes along a path results in a sequence in the given binary tree.

Example 1:

Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
Output: true
Explanation: 
The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the figure). 
Other valid sequences are: 
0 -> 1 -> 1 -> 0 
0 -> 0 -> 0
Example 2:

Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,0,1]
Output: false 
Explanation: The path 0 -> 0 -> 1 does not exist, therefore it is not even a sequence.
Example 3:

Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,1]
Output: false
Explanation: The path 0 -> 1 -> 1 is a sequence, but it is not a valid sequence.
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
    bool isValidSequence(TreeNode* root, vector<int>& arr, int index=0) {
        int n = (int)arr.size();
        if(!root||!n||index>=n) return false;
        if(!root->left&&!root->right&&root->val==arr[index]&&(index==n-1)) return true;
        return (
            root->val==arr[index] &&
            (isValidSequence(root->left,arr,index+1) || 
            isValidSequence(root->right,arr,index+1))
        );
    }
};

class Solution2 {
public:
    bool check(TreeNode* node, vector<int>& arr, int idx) {
        if (!node) return false;
        if (node->val != arr[idx]) return false;
        if (idx + 1 == arr.size()) return (!node->left && !node->right);
        return check(node->left, arr, idx+1) || check(node->right, arr, idx+1);
    }

    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return check(root, arr, 0);
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();