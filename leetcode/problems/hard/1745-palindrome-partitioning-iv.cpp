/*
Palindrome Partitioning IV
https://leetcode.com/problems/palindrome-partitioning-iv/

Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.​​​​​

A string is said to be palindrome if it the same string when reversed.

 

Example 1:

Input: s = "abcbdd"
Output: true
Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.
Example 2:

Input: s = "bcbddxy"
Output: false
Explanation: s cannot be split into 3 palindromes.
 

Constraints:

3 <= s.length <= 2000
s​​​​​​ consists only of lowercase English letters.
*/

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = (int) s.size();
        // dp[i][j] : s[i .. j] is a palindrome
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) dp[i][i] = 1;
        for(int k = 2; k <= n; k++) {
            for(int i = 0; i < n - k + 1; i++) {
                if(k == 2) dp[i][i + k - 1] = s[i] == s[i + k - 1];
                else dp[i][i + k - 1] = dp[i + 1][i + k - 2] && s[i] == s[i + k - 1];
            }
        }
        int found = 0;
        for(int i = 0; i < n - 2; i++) {
            if(dp[0][i] == 0) continue;
            for(int j = i + 1; j < n - 1; j++) {
                if(dp[i + 1][j] && dp[j + 1][n - 1]) {
                	// s[0 .. i] + s[i + 1 .. j] + s[j + 1 .. n - 1]
                    found = 1;
                    break;
                }
            }
        }
        
        return found;
    }
};