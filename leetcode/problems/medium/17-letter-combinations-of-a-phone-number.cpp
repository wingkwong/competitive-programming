/*
Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

class Solution {
public:
    void backtrack(vector<string> &v, vector<string> &ans, string s, string digits, int idx) {
        if(idx == (int)digits.size()) {
            ans.push_back(s);
            return;
        }
        for(int i = 0; i < v[digits[idx] - '0'].size(); i++) {
            s.push_back(v[digits[idx] - '0'][i]);
            backtrack(v, ans, s, digits, idx + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if((int) digits.size() == 0) return ans;
        vector<string> v{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string s;
        int idx = 0;
        backtrack(v, ans, s, digits, idx);
        return ans;
    }
};