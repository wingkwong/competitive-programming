/*
Combination Sum II

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

class Solution {
public:
void backtrack(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& tmp, int start) {
        if(target < 0) return;
        if(target == 0) {
            ans.push_back(tmp);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            if(i != start && candidates[i] == candidates[i - 1]) continue;
            tmp.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], ans, tmp, i + 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        backtrack(candidates, target, ans, tmp, 0);
        return ans;
    }
};