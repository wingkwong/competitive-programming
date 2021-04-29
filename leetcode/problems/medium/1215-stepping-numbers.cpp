/*
Stepping Numbers
https://leetcode.com/problems/stepping-numbers/

A Stepping Number is an integer such that all of its adjacent digits have an absolute difference of exactly 1. For example, 321 is a Stepping Number while 421 is not.

Given two integers low and high, find and return a sorted list of all the Stepping Numbers in the range [low, high] inclusive.

 

Example 1:

Input: low = 0, high = 21
Output: [0,1,2,3,4,5,6,7,8,9,10,12,21]
 

Constraints:

0 <= low <= high <= 2 * 10^9
*/

class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> ans;
        vector<int> q = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        while(!q.empty()) {
            vector<int> p;
            for(int i = 0; i < q.size() && q[i] <= high; i++) {
                if(q[i] >= low) ans.push_back(q[i]);
                if(q[i] != 0 && (long) q[i] * 10 < INT_MAX) {
                    if(q[i] % 10 > 0) p.push_back(q[i] * 10 + q[i] % 10 - 1);
                    if(q[i] % 10 < 9) p.push_back(q[i] * 10 + q[i] % 10 + 1);
                }
            }
            swap(p, q);
        }
        return ans;
    }
};