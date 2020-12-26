/*
Palindrome Partitioning
https://leetcode.com/problems/palindrome-partitioning/

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/

class Solution {
public:
    bool is_palindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }
    
    void backtrack(string s, vector<vector<string>>& ans, vector<string>& tmp, int start) {
        if(start == s.size()) {
            ans.push_back(tmp);
            return;
        }
        for(int i = start; i < s.size(); i++) {
            // xxxxxxxxxx
            //. ^.   ^
            if(!is_palindrome(s.substr(start, i - start + 1))) continue;
            tmp.push_back(s.substr(start, i - start + 1));
            backtrack(s, ans, tmp, i + 1);
            tmp.pop_back();
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        backtrack(s, ans, tmp, 0);
        return ans;
    }
};