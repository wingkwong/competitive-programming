/*
Equal Sum Arrays With Minimum Number of Operations
https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/

You are given two arrays of integers nums1 and nums2, possibly of different lengths. The values in the arrays are between 1 and 6, inclusive.

In one operation, you can change any integer's value in any of the arrays to any value between 1 and 6, inclusive.

Return the minimum number of operations required to make the sum of values in nums1 equal to the sum of values in nums2. Return -1​​​​​ if it is not possible to make the sum of the two arrays equal.

 

Example 1:

Input: nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
Output: 3
Explanation: You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed.
- Change nums2[0] to 6. nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2].
- Change nums1[5] to 1. nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2].
- Change nums1[2] to 2. nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2].
Example 2:

Input: nums1 = [1,1,1,1,1,1,1], nums2 = [6]
Output: -1
Explanation: There is no way to decrease the sum of nums1 or to increase the sum of nums2 to make them equal.
Example 3:

Input: nums1 = [6,6], nums2 = [1]
Output: 3
Explanation: You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed. 
- Change nums1[0] to 2. nums1 = [2,6], nums2 = [1].
- Change nums1[1] to 2. nums1 = [2,2], nums2 = [1].
- Change nums2[0] to 4. nums1 = [2,2], nums2 = [4].
 

Constraints:

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[i] <= 6
*/

class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size(), ans = 0, s1 = 0, s2 = 0;
        for(int x : a) s1 += x;
        for(int x : b) s2 += x;
        if(s1 > s2) {
            swap(s1, s2);
            swap(a, b);
        }
        // s1 <= s2
        // either
        // 1. make some elements to 6 in a 
        // 2. make some elements to 1 in b
        int d = s2 - s1;
        if(d == 0) return 0;
        vector<int> c;
        for(int x : a) c.push_back(6 - x);
        for(int x : b) c.push_back(x - 1);
        sort(c.rbegin(), c.rend());
        for(int x : c) {
            ans++, d -= x;
            if(d <= 0) return ans;
        }
        return -1;
    }
};