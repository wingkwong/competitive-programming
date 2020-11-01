/*
Sort Array by Increasing Frequency
https://leetcode.com/problems/sort-array-by-increasing-frequency/

Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

 

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
 

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100
*/

// AC - 24 ms
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int n : nums) m[n]++;
        sort(nums.begin(), nums.end(), [&](int a, int b){
           return m[a] == m[b] ? a > b : m[a] < m[b];
        });
        return nums;
    }
};

// AC - 16ms
class Solution2 {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int n : nums) m[n]++;
        vector<pair<int, int>> v;
        for(auto k : m) v.push_back({k.first, k.second});
        sort(v.begin(), v.end(), [](pair<int, int>& p1, pair<int, int>& p2){
           return p1.second < p2.second || (p1.second == p2.second && p1.first > p2.first ); 
        });
        vector<int> ans;
        for(auto k: v) {
            for(int i = 0; i < k.second; i++) {
                ans.push_back(k.first);
            }
        }
        return ans;
    }
};