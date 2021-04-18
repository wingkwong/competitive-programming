/*
Single Number II

Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0, k = 3;
        for(int i = 0; i < 32; i++) {
            int cnt = 0, mask = 1 << i;
            for(auto x : nums) {
                if(x & mask) {
                    cnt++;
                }
            }
            if(cnt % k == 1) {
                ans |= mask;
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0,twos=0;
        // like a states of machine (00,01,11)
        // first bit: 0 -> 0 -> 1 -> back to 0
        // second bit: 0 -> 1 -> 0 -> back to 0
        for(int n:nums){
            // if twos is 1, ones would become 0
            // if twos is 0, ones will hold the ans
            // same as if(twos==1) ones=0
            ones=(ones^n)&~twos;
            // ones will be 0 when the number is received twice
            twos=(twos^n)&~ones;
        }
        return ones;
    }
};