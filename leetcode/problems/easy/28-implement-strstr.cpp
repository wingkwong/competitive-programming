/*
Implement strStr()
https://leetcode.com/problems/implement-strstr/

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Example 3:

Input: haystack = "", needle = ""
Output: 0

Constraints:

0 <= haystack.length, needle.length <= 5 * 104
haystack and needle consist of only lower-case English characters.
*/

class Solution {
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
    
    int strStr(string haystack, string needle) {
        int k = (int) needle.size();
        if(haystack == needle || k == 0) return 0;
        string s = needle + "$" + haystack;
        vector<int> z = z_function(s);
        int n = (int) s.size();
        // 01234567
        // ll$hello
        //      ^
        // 5(i) - 2(k) - 1($)
        for(int i = 0; i < n; i++) {
            if(z[i] == k) {
                return i - k - 1;
            }
        }
        return -1;
    }
};