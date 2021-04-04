/*
Minimum Absolute Sum Difference
https://leetcode.com/problems/minimum-absolute-sum-difference/

You are given two positive integer arrays nums1 and nums2, both of length n.

The absolute sum difference of arrays nums1 and nums2 is defined as the sum of |nums1[i] - nums2[i]| for each 0 <= i < n (0-indexed).

You can replace at most one element of nums1 with any other element in nums1 to minimize the absolute sum difference.

Return the minimum absolute sum difference after replacing at most one element in the array nums1. Since the answer may be large, return it modulo 109 + 7.

|x| is defined as:

x if x >= 0, or
-x if x < 0.
 

Example 1:

Input: nums1 = [1,7,5], nums2 = [2,3,5]
Output: 3
Explanation: There are two possible optimal solutions:
- Replace the second element with the first: [1,7,5] => [1,1,5], or
- Replace the second element with the third: [1,7,5] => [1,5,5].
Both will yield an absolute sum difference of |1-2| + (|1-3| or |5-3|) + |5-5| = 3.
Example 2:

Input: nums1 = [2,4,6,8,10], nums2 = [2,4,6,8,10]
Output: 0
Explanation: nums1 is equal to nums2 so no replacement is needed. This will result in an 
absolute sum difference of 0.
Example 3:

Input: nums1 = [1,10,4,4,2,7], nums2 = [9,3,5,1,7,4]
Output: 20
Explanation: Replace the first element with the second: [1,10,4,4,2,7] => [10,10,4,4,2,7].
This yields an absolute sum difference of |10-9| + |10-3| + |4-5| + |4-1| + |2-7| + |7-4| = 20
 

Constraints:

n == nums1.length
n == nums2.length
1 <= n <= 105
1 <= nums1[i], nums2[i] <= 105
*/

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
		// original_diff_sum - will accumulate sum of difference without replacement
		// mx_decrement - will store max decrement possible after replacement at any index of nums1
		long n = size(nums1), original_diff_sum = 0, mx_decrement = 0, M = 1e9 + 7;
		set<int> s(nums1.begin(), nums1.end());   // sorted nums1
		for(int i = 0; i < n; i++){
			long cur_diff = abs(nums1[i] - nums2[i]);   // original difference for current index without replacement
			original_diff_sum += cur_diff;
			// find closest element to nums2[i] so that after replacement, diff is minimized
			// lower_bound will return smallest number greater than or equal to nums2[i]. 
			// So we also need to check previous value of lower_bound in s which may further minimize the absolute difference.
			auto it = s.lower_bound(nums2[i]);
			if(it != s.begin()) mx_decrement = max(mx_decrement, cur_diff - abs(*prev(it) - nums2[i]));
			if(it != s.end()) mx_decrement = max(mx_decrement, cur_diff - abs(*it - nums2[i]));            
		}
		// finally apply the maximum decrement that can be done after replacement
		return (original_diff_sum - mx_decrement) % M;
	}
};

// WA
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, M = 1e9 + 7, n = (int) nums1.size(), mx = -1, mx_i = 0;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = abs(nums1[i] - nums2[i]);
            if(a[i] > mx) {
                mx = a[i];
                mx_i = i;
            }
        }
        int mi = INT_MAX, mi_i = 0;
        for(int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[mx_i]);
            if(d < mi) {
                mi = d;
                mi_i = i;
            }
        }
        nums1[mx_i] = nums1[mi_i];
        for(int i = 0; i < n; i++) {
            ans += abs(nums1[i] - nums2[i]);
            ans %= M;
        }
        return ans; 
    }
};