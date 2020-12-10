/*
Shortest Palindrome
https://leetcode.com/problems/shortest-palindrome/

Given a string s, you can convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
 

Constraints:

0 <= s.length <= 5 * 104
s consists of lowercase English letters only.
*/



// TLE
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string r(s);
        reverse(r.begin(), r.end());
        for(int i = 0; i < n; i++) {
            if(s.substr(0, n - i) == r.substr(i)) {
                return r.substr(0, i) + s;
            }
        }
        return "";
    }
};


// AC 
// Solved by Z Algorithm
class Solution {
public:
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
    
    string shortestPalindrome(string s) {
        string r(s);
        reverse(r.begin(), r.end());
        string k = s + "$" + r;
        vector<int> z = z_function(k);
        int n = k.size();
        
        // s = abcd
        // r = dcba
        // k = abcd$dcba
        // z = 000000001
        
        for(int i = 0; i < n; i++) {
            if(z[i] == n - i) {
                string s2 = s.substr(n - i);
                reverse(s2.begin(), s2.end());
                return s2 + s;
            }
        }
        return "";
    }
};

