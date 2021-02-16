/*
Letter Case Permutation
https://leetcode.com/problems/letter-case-permutation/

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.
 

Example 1:

Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: S = "3z4"
Output: ["3z4","3Z4"]
Example 3:

Input: S = "12345"
Output: ["12345"]
Example 4:

Input: S = "0"
Output: ["0"]
 

Constraints:

S will be a string with length between 1 and 12.
S will consist only of letters or digits.
*/

class Solution {
public:
    void backtrack(string &s, int i, vector<string> &ans) {
        if(i == s.size()) {
            ans.push_back(s);
            return;
        }
        // handle letter / digit
        backtrack(s, i + 1, ans);
        if(isalpha(s[i])) {
            // A: 1 0000 0001
            // a: 1 0010 0001
            // Z: 1 0001 1010
            // z: 1 0011 1010
            // a -> A / A -> a
            s[i] ^= (1 << 5);
            // A -> a / a -> A
            backtrack(s, i + 1, ans);
            
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        backtrack(S, 0, ans);
        return ans;
    }
};