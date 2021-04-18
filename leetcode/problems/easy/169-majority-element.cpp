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
        // Boyer-Moore Voting Algorithm
        int i = 0, m = 0;
        for(int x : nums) {
            if(i == 0) m = x, i = 1;
            else if(m == x) i++;
            else i--;
        }
        return m;
    }
};

class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        // simply solved by Boyer-Moore Voting Algorithm
        // There can be at most one majority element which is more than ⌊n/2⌋ times.
        // There can be at most two majority elements which are more than ⌊n/3⌋ times.
        // There can be at most three majority elements which are more than ⌊n/4⌋ times.
        int c1, cnt1=0;
        for(int n:nums){
            if(cnt1==0) c1=n;
            if(n==c1) cnt1++;
            else cnt1--;
        }
        return c1;
    }
};


class Solution3 {
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

class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        int n = (int)nums.size();
        int k = n/2;
        sort(nums.begin(),nums.end());
        return nums[k];
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();