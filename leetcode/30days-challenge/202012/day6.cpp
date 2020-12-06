/*
Populating Next Right Pointers in Each Node II
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 

Example 1:

Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        root->next = NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int n = (int) q.size();
            vector<Node*> t;
            for(int i = 0; i < n; i++) {
                Node* p = q.front();
                q.pop();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
                t.push_back(p);
            }
            for(int i = 0; i + 1 < (int) t.size(); i++) {
                t[i]->next = t[i + 1];
            }
        }
        return root;
    }
};
