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
    int solve(LLNode* node) {
        if(node==NULL) return 0;
        int ans=1;
        while(node->next){
            ans++;
            node=node->next;
        }
        return ans;
    }
};
