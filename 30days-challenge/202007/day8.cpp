/*
3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // approach: 
        // sort the array first
        // fix one value, then find the another two values
        // if the sum is greater than the target, resize the window from the right by 1
        // if it is smaller than that, resize the window from the left by 1
        // if it is same, add it to a set to de-duplicate the result
        int n = nums.size();
        vector<vector<int>> ans;
        if(n<3) return ans;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int val=nums[i];
            int l=i+1;
            int r=n-1;
            while(l<r){
                int sum=val+nums[l]+nums[r];
                if(sum==0) s.insert({val,nums[l++],nums[r--]});
                else if(sum>0) r--;
                else l++;
            }
        }
        for(auto x:s) ans.push_back(x);
        return ans;
    }
};