/*
Subsets

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

// bitmask
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        // number of subsets for n elements would be 2^n
        // because for each element, you can choose to take it or not
        // if take = 1, don't take = 0, then we can use bit manipulation 
        int p = 1 << n; // 1*2^n
        vector<vector<int>> ans;
        for(int i = 0; i < p; i++){
            vector<int> t; 
            for(int j = 0; j < n; j++){
               if((1 << j) & i) t.emplace_back(nums[j]); 
            }
            ans.emplace_back(t);
        }
        return ans;
    }
};

// backtracking 
class Solution2 {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& tmp, vector<int>& nums, int start) {
        ans.push_back(tmp);    
        for(int i = start; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            backtrack(ans, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        backtrack(ans, tmp, nums,  0);
        return ans;
    }
};