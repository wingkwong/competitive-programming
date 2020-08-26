/*
Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed. 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {.
        // no head -> head is NULL
        // no head->next -> head exists. return head. e.g. [1]
        if(!head||!head->next) return head;
        // call the function self as swap(head.next.next) to swap the rest of the list following the first two nodes.
        ListNode* n=swapPairs(head->next->next);
        // swap the first two nodes in the list, i.e. head and head.next;
        ListNode* t=head;
        head=head->next;
        head->next=t;
        // attach the returned head of the sub-list with the two nodes swapped to form a new linked list.
        head->next->next=n;
        return head;
    }
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();