/*
Maximum Subarray Sum with One Deletion
https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/

Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.

Example 1:

Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.
Example 2:

Input: arr = [1,-2,-2,3]
Output: 3
Explanation: We just choose [3] and it's the maximum sum.
Example 3:

Input: arr = [-1,-1,-1,-1]
Output: -1
Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.
 

Constraints:

1 <= arr.length <= 105
-104 <= arr[i] <= 104
*/

class Solution {
public:
    int maximumSum(vector<int>& arr) {
    	// without deletion -> can be solved by kadane's algorithm 
    	// with deletion -> find the max of f[i - 1] + b[i + 1] 
    	// where f[i] and b[i] are the max subarray sum from starting to i-th index 
    	// and from i-th index to ending respectively
        int n = (int) arr.size();
        vector<int> f(n), b(n); // forward, backward
        int ans = INT_MIN, f_sum = 0, b_sum = 0;
        for(int i = 0; i < n; i++) {
            f_sum += arr[i], b_sum += arr[n - 1 - i];
            ans = max({ans, f_sum, b_sum});
            f[i] = f_sum, b[n - 1 - i] = b_sum;
            f_sum = max(f_sum, 0), b_sum = max(b_sum, 0);
        }
        for(int i = 1; i < n - 1; i++) {
            ans = max({ans, f[i - 1] + b[i + 1]});
        }
        return ans;
    }
};