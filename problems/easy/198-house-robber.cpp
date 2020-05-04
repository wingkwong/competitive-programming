/*
House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*/

// Find recursive relation
// rob(i) = max( rob(i-2)+MoneyInTheCurrentHouse, rob(i-1) )

// Recursive (top-down)
// You will get Time Limit Exceeded
class Solution {
public:
    int rob(vector<int>& nums) {
        return f(nums, (int)nums.size()-1);
    }
private:
    int f(vector<int>& nums, int i) {
        if(i<0) return 0;
        return max(f(nums,i-2)+nums[i],f(nums,i-1));
    }
};

// Recursive + memo (top-down)
class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = (int) nums.size();
        vector<int> memo(sz+1,-1);
        return f(nums, memo, sz-1);
    }
private:
    int f(vector<int>& nums, vector<int>& memo, int i) {
        if(i<0) return 0;
        if(memo[i]>=0) return memo[i];
        memo[i] = max(f(nums,memo,i-2)+nums[i],f(nums,memo,i-1));
        return memo[i];
    }
};

// Iterative + memo (bottom-up)
class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = (int) nums.size();
        if(sz==0) return 0;
        vector<int> memo(sz+1);
        memo[0] = 0;
        memo[1] = nums[0];
        for(int i=1;i<sz;i++){
            memo[i+1] = max(memo[i], memo[i-1]+nums[i]);
        }
        return memo[n];
    }
};

// Iterative + N variables (bottom-up)
// prev2 - prev1 - currentNumber
class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = (int) nums.size();
        if(sz==0) return 0;
        int prev2 = 0, prev1 = 0;
        for(int num:nums){
            // memo[i+1] = max(memo[i], memo[i-1]+nums[i]);
            int tmp = prev1;
            prev1=max(prev2+num,prev1);
            prev2=tmp;
        }
        return prev1;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();