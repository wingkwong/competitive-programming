/*
Count Number of Homogenous Substrings
https://leetcode.com/problems/count-number-of-homogenous-substrings/

Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 109 + 7.

A string is homogenous if all the characters of the string are the same.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "abbcccaa"
Output: 13
Explanation: The homogenous substrings are listed as below:
"a"   appears 3 times.
"aa"  appears 1 time.
"b"   appears 2 times.
"bb"  appears 1 time.
"c"   appears 3 times.
"cc"  appears 2 times.
"ccc" appears 1 time.
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.
Example 2:

Input: s = "xy"
Output: 2
Explanation: The homogenous substrings are "x" and "y".
Example 3:

Input: s = "zzzzz"
Output: 15
 

Constraints:

1 <= s.length <= 105
s consists of lowercase letters.

*/

class Solution {
public:
    int countHomogenous(string s) {
        int n = (int) s.size(), M = 1e9 + 7;
        // same idea as solution 2 - but cleaner
        int cnt = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            if(i > 0 && s[i] == s[i - 1]) cnt++;
            else cnt = 1;
            ans = (ans + cnt) % M; 
        }
        return ans;
    }
};


class Solution2 {
public:
    int countHomogenous(string s) {
        int n = (int) s.size(), M = 1e9 + 7;
        long long cnt = 1, ans = 0, i = 0, j = 1;
  		// For "a" : 1
		// For "aa": 3 (1 + 2)
		// For "aaa": 6 (1 + 2 + 3)
        while(j < n) {
            if(s[i] == s[j]) cnt++;
            else {
                ans += cnt * (cnt + 1) / 2;
                ans %= M;
                i = j, cnt = 1;
            }
            j++;
        }
        ans += cnt * (cnt + 1) / 2;
        ans %= M;
        return ans;
    }
};