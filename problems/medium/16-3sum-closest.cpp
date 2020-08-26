/*
16. 3Sum Closest


Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution. 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 

Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int diff = INT_MAX;
        for(int i=0;i<n&&diff!=0;i++){
            int l=i+1, r=n-1;
            while(l<r){
                // just like 3-sum but find the absolute difference
                int sum = nums[i]+nums[l]+nums[r];
                if(abs(target-sum)<abs(diff)){
                    diff=target-sum;
                }
                if(sum>target) r--;
                else l++;
            }
        }
        return target-diff;
    }
};