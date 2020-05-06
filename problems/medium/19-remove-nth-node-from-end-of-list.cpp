/*
Remove Nth Node From End of List

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if head is NULL, return NULL
       if(!head) return NULL;
        // declare a slow & a faster pointer
        ListNode* slow=head, *fast=head;
        // move the fast pointer n times
        while(n--) fast=fast->next;
        // if the fast reaches null, return head->next
        // Example:
        // [1,2]
        // 2
        if(!fast) return head->next;
        // keep traversing each node until the fast pointer reaches NULL
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        // set the next node to next next node
        slow->next = slow->next->next;
        return head;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();