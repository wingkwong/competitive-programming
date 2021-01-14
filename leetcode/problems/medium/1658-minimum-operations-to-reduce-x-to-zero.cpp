/*
Minimum Operations to Reduce X to Zero
https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
    	// left + (sum - x) + right
    	// left + right == x
        int n = (int) nums.size(), sum = 0;
        for(int x: nums) sum += x;
        int l = 0, r = 0, cur = 0, ans = -1;
        if(x > sum) return ans;
        for(; r < n; r++) {
            cur += nums[r];
            while(cur > sum - x && l <= r) {
                cur -= nums[l++];
            }
            if(cur == sum - x) {
                ans = max(ans, r - l + 1);
            }
        }
        if(ans == -1) return ans;
        return n - ans;
    }
};