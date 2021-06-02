/*
Interleaving String
https://leetcode.com/problems/interleaving-string/

Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

 

Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.
 

Follow up: Could you solve it using only O(s2.length) additional memory space?
*/

class Solution {
public:
    int m, n, b;
    int dp[105][105][205];
    
    bool ok(string s1, string s2, string s3, int i, int j, int k) {
        if(i == m && j == n && k == b) return true;
        if(k >= b) return false;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        return dp[i][j][k] = (s1[i] == s3[k] && ok(s1, s2, s3, i + 1, j, k + 1)) || (s2[j] == s3[k] && ok(s1, s2, s3, i, j + 1, k + 1));
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        m = s1.size(), n = s2.size(), b = s3.size();
        return ok(s1, s2, s3, 0, 0, 0);
    }
};