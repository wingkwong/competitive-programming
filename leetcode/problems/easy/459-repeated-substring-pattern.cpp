/*
Repeated Substring Pattern

Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

 

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s+s).substr(1,s.size()*2-2).find(s)!=-1;
    }
};

class Solution2 {
public:
    // z-algorithm
    vector<int> z_function(string s) {
        int n = (int) s.length();
        vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r)
                z[i] = min (r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        return z;
    }
    
    bool repeatedSubstringPattern(string s) {
        vector<int> z = z_function(s);
        int n = (int) s.size();
        for(int i = 1; i <= n / 2; i++) {
            if(z[i] == n - i && n % (n - z[i]) == 0) return true;
        }
        return false;
    }
};