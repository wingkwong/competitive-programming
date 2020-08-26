/*
Pseudo-Palindromic Paths in a Binary Tree

Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

Example 1:

Input: root = [2,3,1,3,1,null,1]
Output: 2 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
Example 2:

Input: root = [2,1,1,1,3,null,null,null,null,null,1]
Output: 1 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
Example 3:

Input: root = [9]
Output: 1
 

Constraints:

The given binary tree will have between 1 and 10^5 nodes.
Node values are digits from 1 to 9.
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
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(10,0);
        dfs(root,v);
        return ans;
    }
private:
    int ans=0;
    void dfs(TreeNode* root, vector<int> v){
        // dfs approach
        // count each digit on the path to each leaf node
        // a palindrome should either have
        // - all digits present of EVEN count
        // - or one digit of ODD count and the rest of them is even
        // hence, check if there is only 0 or 1 odd numbers in the number of digits 
        if(!root) return;
        v[root->val]++;
        if(!root->left&&!root->right){
            int odd=0;
            for(int x:v){
                if(x%2) odd++;
            }
            if(odd<=1) ans++;
            return;
        }
        dfs(root->left,v);
        dfs(root->right,v);
    }
};

class Solution2 {
public:
    int findHeight(struct TreeNode* node) { 
        if (node == NULL) return 0; 
        int leftHeight = findHeight(node->left); 
        int rightHeight = findHeight(node->right); 
        return 1+(leftHeight>rightHeight?leftHeight:rightHeight); 
    } 

    bool canFormPalindrome(string str) { 
        vector<char> list; 
        for (int i = 0; i < str.length(); i++) { 
            auto pos = find(list.begin(), list.end(), str[i]); 
            if (pos != list.end()){ 
                auto position = find(list.begin(), list.end(),str[i]); 
                list.erase(position); 
            } else list.push_back(str[i]); 
        } 
        if (str.length()%2==0&&list.empty()||(str.length()%2==1&&list.size()==1)) return true; 
        else return false; 

    }  

    bool isPathPal(int* path, int index) { 
        int i = 0; 
        string s; 
        while (i <= index) { 
            s += to_string(path[i]); 
            i += 1; 
        } 
        return canFormPalindrome(s); 
    } 

    void helper(struct TreeNode* node, int* path, int index) { 
        if (node==NULL) return; 
        path[index] = node->val; 
        helper(node->left,path,index+1); 
        helper(node->right,path,index+1); 
        if (node->left==NULL&&node->right==NULL) { 
            if (isPathPal(path, index)) ans++;
        } 
    } 
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int height=findHeight(root);
        int path[height];
        memset(path,0,sizeof(int)*height);
        helper(root,path,0);
        return ans;
    }
private:
    int ans=0;
};