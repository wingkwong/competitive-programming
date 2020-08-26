/*
Missing Number

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sz = (int)nums.size();
        int ans = sz;
        for(int i=0;i<sz;i++) ans ^= (i^nums[i]);
        // input: [0,1,3,4]
        // =4^(0^0)^(1^1)^(2^3)^(3^4)
        // =(4^4)^(0^0)^(1^1)^(3^3)^2
        // =0^0^0^0^2
        // =2
        return ans;
    }
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

