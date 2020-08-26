/*
Single Number

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1

Example 2:

Input: [4,1,2,1,2]
Output: 4
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int f = nums[0];
        for(int i=1;i<nums.size();i++){
            // XOR Operator is commutative and copies the bit if it is set in one operand but not both
            // 4,1,2,1,2 -> 4^1^2^1^2 -> 4^(1^1)^(2^2) -> 4^0^0 -> 4
            f ^= nums[i];
        }
        return f;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();