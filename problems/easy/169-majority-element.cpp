/*
Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = (int)nums.size();
        int k = n/2;
        unordered_map<int,int> m;
        for(int num:nums) m[num]++;
        for(int num:nums) {
            if(m[num]>k) return num;
        }
        return -1;
    }
};

class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int n = (int)nums.size();
        int k = n/2;
        sort(nums.begin(),nums.end());
        return nums[k];
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();