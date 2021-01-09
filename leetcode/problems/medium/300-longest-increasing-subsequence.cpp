/*
Longest Increasing Subsequence

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(int n : nums) {
            auto it = lower_bound(lis.begin(), lis.end(), n);
            if(it == lis.end()) lis.push_back(n);
            else *it = n;
        }
        return (int) lis.size();
    }
};

class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        //  L(i) = 1 + max( L(j) ) where 0 < j < i and arr[j] < arr[i]; or
        //  L(i) = 1, if no such j exists.
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> dp(n + 1, 1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        // find out the max in dp
        int ans=0;
        for(int k: dp) ans = max(ans, k);
        return ans;
        // or return *max_element(dp.begin(),dp.end());
    }
};