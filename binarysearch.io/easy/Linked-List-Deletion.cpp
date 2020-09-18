/*
Linked List Deletion
https://binarysearch.io/problems/Linked-List-Deletion

Given a singly linked list node, and an integer target, return the same linked list with all nodes whose value is target removed.

Example 1
Input

node = 0 → 1 → 1 → 2
target = 1
Output

0 → 2
*/

#include "solution.hpp"
using namespace std;

/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
class Solution {
    public:
    LLNode* solve(LLNode* node, int target) {
        while(node&&node->val==target) node=node->next;
        LLNode* cur=node;
        while(cur&&cur->next){
            if(cur->next->val==target) cur->next = cur->next->next; 
            else cur = cur->next;
        }
        return node;
    }
};
