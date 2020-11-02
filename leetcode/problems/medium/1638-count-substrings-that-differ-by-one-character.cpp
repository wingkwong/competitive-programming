/*
Count Substrings That Differ by One Character
https://leetcode.com/problems/count-substrings-that-differ-by-one-character/

Given two strings s and t, find the number of ways you can choose a non-empty substring of s and replace a single character by a different character such that the resulting substring is a substring of t. In other words, find the number of substrings in s that differ from some substring in t by exactly one character.

For example, the underlined substrings in "computer" and "computation" only differ by the 'e'/'a', so this is a valid way.

Return the number of substrings that satisfy the condition above.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "aba", t = "baba"
Output: 6
Explanation: The following are the pairs of substrings from s and t that differ by exactly 1 character:
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
The underlined portions are the substrings that are chosen from s and t.
​​Example 2:
Input: s = "ab", t = "bb"
Output: 3
Explanation: The following are the pairs of substrings from s and t that differ by 1 character:
("ab", "bb")
("ab", "bb")
("ab", "bb")
​​​​The underlined portions are the substrings that are chosen from s and t.
Example 3:
Input: s = "a", t = "a"
Output: 0
Example 4:

Input: s = "abe", t = "bbc"
Output: 10
 

Constraints:

1 <= s.length, t.length <= 100
s and t consist of lowercase English letters only.
*/

class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size(), ans = 0;
        // brute-force 
        for(int i = 0; i < m ; i++) {
            for(int j = i; j < m; j++) {
                for(int x = 0; x < n; x++) {
                    for(int y = x; y < n; y++) {
                        // compare only both length of a and b are same
                        if(j - i != y - x) continue;
                        string a = s.substr(i, j - i + 1);
                        string b = t.substr(x, y - x + 1);
                        int diff = 0;
                        for(int k = 0; k < a.size(); k++) {
                            diff += a[k] != b[k];
                        }
                        if(diff == 1) ans++;
                    }
                }
            }
        }
        return ans;
    }
};