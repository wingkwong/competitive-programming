/*
 Longest Nice Substring
 https://leetcode.com/problems/longest-nice-substring/

 A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.

Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.

 

Example 1:

Input: s = "YazaAay"
Output: "aAa"
Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
"aAa" is the longest nice substring.
Example 2:

Input: s = "Bb"
Output: "Bb"
Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
Example 3:

Input: s = "c"
Output: ""
Explanation: There are no nice substrings.
Example 4:

Input: s = "dDzeE"
Output: "dD"
Explanation: Both "dD" and "eE" are the longest nice substrings.
As there are multiple longest nice substrings, return "dD" since it occurs earlier.
 

Constraints:

1 <= s.length <= 100
s consists of uppercase and lowercase English letters.
*/

class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++) {
            unordered_map<char, int> m;
            for(int j = i; j < n; j++) {
                m[s[j]]++;
                if(j >= i + 1) {
                    int ok = 1;
                    for(auto k : m) {
                        if(m[(char)tolower(k.first)] == 0 || m[(char)toupper(k.first)] == 0) {
                            ok = 0;
                        }
                    }
                    if(ok) {
                        int k = (int) ans.size();
                        if(j - i + 1 > k) {
                            ans = s.substr(i, j - i + 1);
                        }
                    }
                }
            }
        }
        return ans;
    }
};