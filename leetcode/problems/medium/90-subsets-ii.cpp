/*
Subsets II

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& tmp, vector<int>& nums, int start) {
        ans.push_back(tmp);    
        for(int i = start; i < nums.size(); i++) {
            if(i != start && nums[i] == nums[i - 1]) continue;
            tmp.push_back(nums[i]);
            backtrack(ans, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        backtrack(ans, tmp, nums,  0);
        return ans;
    }
};