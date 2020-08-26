/*
Add Digits

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/

class Solution {
public:
    int addDigits(int num) {
        // Congruence formula
        // dr(n) = 0 if n == 0
        // dr(n) = (b-1) if n != 0 and n % (b-1) == 0
        // dr(n) = n mod (b-1) if n % (b-1) != 0
        // https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};