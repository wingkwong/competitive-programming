/*
Minimum Difference Between Largest and Smallest Value in Three Moves

Given an array nums, you are allowed to choose one element of nums and change it by any value in one move.

Return the minimum difference between the largest and smallest value of nums after perfoming at most 3 moves.

 

Example 1:

Input: nums = [5,3,2,4]
Output: 0
Explanation: Change the array [5,3,2,4] to [2,2,2,2].
The difference between the maximum and minimum is 2-2 = 0.
Example 2:

Input: nums = [1,5,0,10,14]
Output: 1
Explanation: Change the array [1,5,0,10,14] to [1,1,0,1,1]. 
The difference between the maximum and minimum is 1-0 = 1.
Example 3:

Input: nums = [6,6,0,1,1,4,6]
Output: 2
Example 4:

Input: nums = [1,5,6,14,15]
Output: 1
 

Constraints:

1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
*/

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        // we can change at most 3 moves 
        // if n<=3, we can change all elements to the same value
        if(n<=3) return 0;
        // sort the nums
        sort(nums.begin(),nums.end());
        // there are 4 possible solutions
        return min({
            // change the first 3
            nums[n-1]-nums[3],
            // change the first 2, and the last 1
            nums[n-2]-nums[2],
            // change the first 1, and the last 2
            nums[n-3]-nums[1],
            // change the last 3
            nums[n-4]-nums[0]
        });
    }
};
