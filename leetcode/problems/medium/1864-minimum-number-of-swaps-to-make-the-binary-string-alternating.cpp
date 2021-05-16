/*
Minimum Number of Swaps to Make the Binary String Alternating
https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/

Given a binary string s, return the minimum number of character swaps to make it alternating, or -1 if it is impossible.

The string is called alternating if no two adjacent characters are equal. For example, the strings "010" and "1010" are alternating, while the string "0100" is not.

Any two characters may be swapped, even if they are not adjacent.

 

Example 1:

Input: s = "111000"
Output: 1
Explanation: Swap positions 1 and 4: "111000" -> "101010"
The string is now alternating.
Example 2:

Input: s = "010"
Output: 0
Explanation: The string is already alternating, no swaps are needed.
Example 3:

Input: s = "1110"
Output: -1
 

Constraints:

1 <= s.length <= 1000
s[i] is either '0' or '1'.
*/

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size(), cnt0 = 0, cnt1 = 0;
        for(int i = 0; i < n; i++) {;
            cnt0 += s[i] == '0', cnt1 += s[i] == '1';
        }
        if(abs(cnt0 - cnt1) > 1) return -1;
        string s1, s2;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) s1 += '0', s2 += '1';
            else s2 += '0', s1 += '1';
        }
        int s1_diff = 0, s2_diff = 0;
        for(int i = 0; i < n; i++) {
            s1_diff += s[i] != s1[i], s2_diff += s[i] != s2[i];
        }
        int ans = INT_MAX;
        // cout << s1_diff << " " << s2_diff << endl;
        if(s1_diff % 2 == 0) ans = min(ans, s1_diff / 2);
        if(s2_diff % 2 == 0) ans = min(ans, s2_diff / 2);
        return ans;
    }
};