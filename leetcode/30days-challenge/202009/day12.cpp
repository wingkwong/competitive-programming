/*
Combination Sum III
https://leetcode.com/problems/combination-sum-iii/

Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void dfs(int k, int n, int i){
        if(k==0&&n==0){
            ans.push_back(tmp);
            return;
        }
        if(k==0) return;
        for(int j=i;j<=9;j++){
            tmp.push_back(j);
            dfs(k-1,n-j,j+1);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        // dfs + backtracking
        dfs(k,n,1);
        return ans;
    }
};