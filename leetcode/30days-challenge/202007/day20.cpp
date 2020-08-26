/*
Remove Linked List Elements

Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // recursive approach
        // [1,2,6,3,4,5,6]
        // 6
        // head->val = 6
        // head->val = 5
        // head->val = 4
        // head->val = 3
        // head->val = 6
        // head->val = 2
        // head->val = 1
        if(head==NULL) return NULL;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};

