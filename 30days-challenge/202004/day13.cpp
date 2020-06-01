/*
Contiguous Array

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        m.insert({0,-1});
        int ans=0,count=0;
        int sz=nums.size();
        for(int i=0;i<sz;i++){
            count+=nums[i]?1:-1;
            if(m.find(count)!=m.end()) {
                ans=max(ans,i-m[count]);
            } else m.insert({count,i});
        }
        return ans;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();