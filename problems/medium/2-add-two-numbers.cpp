/*
Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3=NULL; ListNode **ll3=&l3;
        int c=0;
        while(l1||l2||c){
            int v1=0,v2=0,v3=0;
            // l1 -> 2 -> 4 -> 3 -> NULL
            if(l1){
                v1=l1->val;
                l1=l1->next;
            }
            // l2 -> 5 -> 6 -> 4 -> NULL
            if(l2){
                v2=l2->val;
                l2=l2->next;
            }
            // l3 -> 7 -> 0 > 8(c=1) -> NULL
            v3=v1+v2+c;
            (*ll3)=new ListNode((v1+v2+c)%10);
            ll3=&((*ll3)->next);
            c=v3/10;
        }
        return l3;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();