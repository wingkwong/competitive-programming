/*
Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
*/

// Using Manacher's Algorithm
// AC - 8ms
class Solution {
public:
    string manacher(string s) {
      int n = (int) s.size();
      // d1[i]: the number of palindromes accordingly with odd lengths with centers in the position i.
      // d2[i]: the number of palindromes accordingly with even lengths with centers in the position i. 
      vector<int> d1(n), d2(n);
      int l1 = 0, r1 = -1, l2 = 0, r2 = -1, mx_len = 0, start = 0;
      for (int i = 0; i < n; i++) {
          // ----------------------
          // calculate d1[i]
          // ----------------------
          int k = (i > r1) ? 1 : min(d1[l1 + r1 - i], r1 - i + 1);
          while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
          d1[i] = k--;
          if (i + k > r1) l1 = i - k, r1 = i + k;
          if(d1[i] * 2 > mx_len) start = i - k, mx_len = d1[i] * 2 - 1;
          // ----------------------
          // calculate d2[i] 
          // ----------------------
          k = (i > r2) ? 0 : min(d2[l2 + r2 - i + 1], r2 - i + 1);
          while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
          d2[i] = k--;
          if (i + k > r2) l2 = i - k - 1, r2 = i + k;
          if(d2[i] * 2 > mx_len) start = i - k - 1, mx_len = d2[i] * 2;
      }
      // return the longest palindrome
      return s.substr(start, mx_len);
    }
    
    string longestPalindrome(string s) {
        // Using Manacher's algorithm 
        return manacher(s);
    }
};


// Using DP
// AC - 296 ms
class Solution2 {
public:
    string longestPalindrome(string s) {
        int n = (int) s.size();
        if(n <= 1) return s;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int start = 0, len = 1;
        for(int i = 0; i < n; i++) dp[i][i] = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j]) {
                    if(i + 1 == j || dp[i + 1][j - 1]) {
                        dp[i][j] = 1;
                        if(len < j - i + 1) {
                            start = i;
                            len = j - i + 1;
                        }
                    }
                }
            }
        }
        return s.substr(start, len);
    }
};