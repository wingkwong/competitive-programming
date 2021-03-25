/*
Valid Palindrome II
https://leetcode.com/problems/valid-palindrome-ii/

Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/

class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        // ...i....k.....j...
        for (int k = i; k <= i + (j - i) / 2; k++) {
            if(s[k] != s[j - k + i]) return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int n = s.size();
        for(int i = 0; i < n / 2; i++) {
            int j = n - 1 - i;
            if(s[i] != s[j]) {
                 // [i + 1 .. j] || [i .. j - 1]
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
            }
        }
        return true;
    }
};