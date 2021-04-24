/*
Generate Parentheses
https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

class Solution {
public:
    vector<string> ans;
    void backtrack(string cur, int open, int close, int n) {
            if(cur.size() == n * 2) {
                ans.push_back(cur);
                return;
            }
            if(open < n) {
                cur.push_back('(');
                backtrack(cur, open + 1, close, n);
                cur.pop_back();
            }
            if(close < open) {
                cur.push_back(')');
                backtrack(cur, open, close + 1, n);
                cur.pop_back();
            }
        };
    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return ans;
    }
};