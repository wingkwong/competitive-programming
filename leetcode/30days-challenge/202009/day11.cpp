/*
Maximum Product Subarray
https://leetcode.com/problems/maximum-product-subarray/

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx, mi, ans;
        mx=mi=ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int tmp=mx;
            mx=max({nums[i],nums[i]*mx,nums[i]*mi});
            mi=min({nums[i],nums[i]*tmp,nums[i]*mi});
            ans=max(ans,mx);
        }
        return ans;
    }
};

class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int n=(int)nums.size(), l=nums[0], r=nums[n-1], ans=nums[0];
        for(int i=1;i<n;i++){
            l*=nums[i];
            r*=nums[n-1-i];
            ans=max({ans,l,r});
        }
        return ans;
    }
};