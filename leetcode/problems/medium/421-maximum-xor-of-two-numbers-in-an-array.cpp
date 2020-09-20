/*
Maximum XOR of Two Numbers in an Array
https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
*/

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans=0, mask=0;
        unordered_set<int> s;
        for(int i=31;i>=0;i--){
            s.clear();
            mask|=(1<<i);
            for(int n:nums) s.insert(mask&n);
            int c=ans|(1<<i);
            for(int pref: s){
                if(s.find(pref^c)!=s.end()){
                    ans=c;
                    break;
                }
            }
            
        }
        return ans;
    }
};