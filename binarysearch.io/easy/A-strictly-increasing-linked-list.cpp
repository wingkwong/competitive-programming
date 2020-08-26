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
    bool solve(LLNode* head) {
        int val = -1;
        while(head!=NULL){
            if(head->val<=val) {
                return false;
            }
            val=head->val;
            head=head->next;
        }
        return true;
    }
};
