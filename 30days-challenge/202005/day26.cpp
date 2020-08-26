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
Note: The length of the given binary array will not exceed 50,000.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;  // <count,index>
        m.insert({0,-1});
        int cnt=0,ans=0;
        for(int i=0;i<nums.size();i++){
            // increase cnt by 1 if it is 1, decrease cnt by 1 if it is 0
            if(nums[i]==1) cnt++;
            else cnt--;
            // find if cnt exists in map
            if(m.count(cnt)){
                // if exist, we may find the possible ans
                ans=max(ans,i-m[cnt]);
            } else {
                // insert {count,index} to map
                m.insert({cnt,i});
            }
        }
        return ans;
    }
};