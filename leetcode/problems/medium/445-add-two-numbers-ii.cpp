/*
Add Two Numbers II

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        for (; l1; l1 = l1->next) s1.push(l1->val); 
        for (; l2; l2 = l2->next) s2.push(l2->val);
        
        ListNode *res = new ListNode(0), *tmp = NULL;
        for (int sum = 0; !s1.empty()||!s2.empty(); tmp = new ListNode(sum/=10), tmp->next = res, res = tmp) {
            if (!s1.empty()) sum += s1.top(), s1.pop(); 
            if (!s2.empty()) sum += s2.top(), s2.pop();
            res->val = sum%10;
        }
        return res->val? res : res->next;  
    }
};