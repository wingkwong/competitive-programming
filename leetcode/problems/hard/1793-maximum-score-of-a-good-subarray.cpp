/*
Maximum Score of a Good Subarray
https://leetcode.com/problems/maximum-score-of-a-good-subarray/

You are given an array of integers nums (0-indexed) and an integer k.

The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.

Return the maximum possible score of a good subarray.

 

Example 1:

Input: nums = [1,4,3,7,4,5], k = 3
Output: 15
Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15. 
Example 2:

Input: nums = [5,5,4,5,4,1,1,1], k = 0
Output: 20
Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 2 * 104
0 <= k < nums.length

*/

class Solution {
public:
    int maximumScore(vector<int>& A, int k) {
        int i = k, j = k, ans = A[k], mi = A[k], n = (int) A.size();
        while(i > 0 || j < n - 1) {
            if(i == 0) j++;
            else if(j == n - 1) i--;
            else if(A[i - 1] < A[j + 1]) j++;
            else i--;
            mi = min(mi, min(A[i], A[j]));
            ans = max(ans, mi * (j - i + 1));
        }
        return ans;
    }
};