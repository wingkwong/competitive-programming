/*
Number of Different Subsequences GCDs
https://leetcode.com/problems/number-of-different-subsequences-gcds/

You are given an array nums that consists of positive integers.

The GCD of a sequence of numbers is defined as the greatest integer that divides all the numbers in the sequence evenly.

For example, the GCD of the sequence [4,6,16] is 2.
A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
Return the number of different GCDs among all non-empty subsequences of nums.

 

Example 1:


Input: nums = [6,10,3]
Output: 5
Explanation: The figure shows all the non-empty subsequences and their GCDs.
The different GCDs are 6, 10, 3, 2, and 1.
Example 2:

Input: nums = [5,15,40,5,6]
Output: 7
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 2 * 105
*/

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        vector<int> factor(200001);
        int n = (int) nums.size();
        for(int i = 0; i < n; i++) {
            // search all factors of nums[i]
            for(int j = 1; j * j <= nums[i]; j++) {
                if(nums[i] % j == 0) {
                    int factor1 = j;
                    int factor2 = nums[i] / j;
                    factor[factor1] = gcd(factor[factor1], nums[i]);
                    factor[factor2] = gcd(factor[factor2], nums[i]);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= 200000; i++) ans += factor[i] == i;
        return ans;
    }
};