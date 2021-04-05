/*
palindrome-linked-list
https://leetcode.com/problems/palindrome-linked-list/

Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        // find the middle node
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // handle odd case
        if(fast) slow = slow->next;
		// reverse the last half of the list
        ListNode *node = slow;
        ListNode *last = nullptr;
        ListNode *next = nullptr;
        while(node){
            next = node->next;
            node->next = last;
            last = node;
            node = next;
        }
		// compare each half of the list
        node = last;
        while(node){
            if (node->val == head->val) node = node->next, head = head->next;
            else return false;
        }
        return true;
    }
};