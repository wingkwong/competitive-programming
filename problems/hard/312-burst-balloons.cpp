/*
Burst Balloons

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
Example:

Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = (int)nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        vector<int> nums1(n+2,1);
        for(int i=0;i<n;i++){
            // 1,nums[0],nums[1],..,nums[n-1],1
            nums1[i+1]=nums[i];
        }
        return f(nums1,dp,1,n);
    }
private:
    int f(vector<int>& nums, vector<vector<int>>& dp, int left, int right){
        if(left>right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        for(int k=left;k<=right; k++){
            dp[left][right] = max(
                dp[left][right],
                // left part: from starting point to the burst point - 1
                f(nums,dp,left,k-1) +
                // middle part: e.g. k=1: 1*nums[0]*1 bc balloons from [left,k-1] and from [k+1,end] are bursted
                nums[left-1]*nums[k]*nums[right+1] +
                // right part: from the burst point + 1 to the end
                f(nums,dp,k+1,right)
            );
        }
        return dp[left][right];
    }
};