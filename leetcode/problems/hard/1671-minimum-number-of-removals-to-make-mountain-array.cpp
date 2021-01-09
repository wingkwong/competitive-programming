/*
Minimum Number of Removals to Make Mountain Array
https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.

Example 1:

Input: nums = [1,3,1]
Output: 0
Explanation: The array itself is a mountain array so we do not need to remove any elements.
Example 2:

Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
Example 3:

Input: nums = [4,3,2,1,1,2,3,1]
Output: 4
Example 4:

Input: nums = [1,2,3,4,4,3,2,1]
Output: 1
 

Constraints:

3 <= nums.length <= 1000
1 <= nums[i] <= 109
It is guaranteed that you can make a mountain array out of nums.
*/


class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = (int) nums.size(), ans = n;
        vector<int> a(n), b(n), lis;
        for(int i = 0; i < n; i++) {
            auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
            a[i] = it - lis.begin();
            if(it == lis.end()) lis.push_back(nums[i]);
            else *it = nums[i];
        }
        lis.clear();
        for(int i = n - 1; i >= 0; i--) {
            auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
            b[i] = it - lis.begin();
            if(it == lis.end()) lis.push_back(nums[i]);
            else *it = nums[i];
        }
        for(int i = 1; i < n; i++) {
            if(a[i] && b[i]) {
                ans = min(ans, n - (a[i] + b[i] + 1));
            }
        }
        return ans;
    }
};


// WA
// class Solution {
// public:
//     int minimumMountainRemovals(vector<int>& nums) {
//         int n = (int) nums.size();
//         vector<int> l(n + 1, 1), r(n + 1, 1);
//         for(int i = 0; i < n; i++) {
//             for(int j = i + 1; j < n; j++) {
//                 if(nums[i] < nums[j]) {
//                     l[j] = max(l[j], l[i] + 1);
//                 }
//             }
//         }
//         for(int i = n - 1; i >= 0; i--) {
//             for(int j = i - 1; j >= 0; j--) {
//                 if(nums[i] < nums[j]) {
//                     r[j] = max(r[j], r[i] + 1);
//                 }
//             }
//         }
//         int mx = 0;
//         for(int i = 1; i < n; i++) mx = max(mx, l[i] + r[i] - 1);
//         return n - mx;
//     }
// };