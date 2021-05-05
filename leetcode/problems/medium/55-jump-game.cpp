/*
Jump Game

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.

*/


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), pos = n - 1;
        for(int i = n - 1; ~i ; i--) {
            if(i + nums[i] >= pos) pos = i;
        }
        return pos == 0;
    }
};


class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int sz = nums.size();
        int pos = sz-1;
        for(int i=sz-1;i>=0;i--) {
            if(i+nums[i]>=pos) {
                pos=i;
            }
        }
        return pos==0;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();