/*
Super Palindromes
https://leetcode.com/problems/super-palindromes/

Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.

Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].

 

Example 1:

Input: left = "4", right = "1000"
Output: 4
Explanation: 4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.
Example 2:

Input: left = "1", right = "2"
Output: 1
 

Constraints:

1 <= left.length, right.length <= 18
left and right consist of only digits.
left and right cannot have leading zeros.
left and right represent integers in the range [1, 1018].
left is less than or equal to right.
*/

class Solution {
public:
    bool isPalindrome(const string &s) {
        return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
    }
    
    int superpalindromesInRange(string left, string right) {
        int ans = 0;
        long l = stol(left), r = stol(right);
        // P = 10 ^ 18
        // R = 10 ^ 9
        // R = k | k'
        // R = 10 ^ 4.5 
        int mxN = 100000;
        // count odd length palindrome
        for(int i = 1; i < mxN; i++) {
            string s = to_string(i);
            for(int j = s.size() - 2; j >= 0; j--) s += s[j];
            long val = stol(s);
            val *= val;
            if(val > r) break;
            if(l <= val && isPalindrome(to_string(val))) ans++;
        }
        
        // count even length palidrome
        for(int i = 1; i < mxN; i++) {
            string s = to_string(i);
            for(int j = s.size() - 1; j >= 0; j--) s += s[j];
            long val = stol(s);
            val *= val;
            if(val > r) break;
            if(l <= val&& isPalindrome(to_string(val))) ans++;
        }
        
        return ans;
    }
};