/*
Sum of Two Integers
https://leetcode.com/problems/sum-of-two-integers/
Given two integers a and b, return the sum of the two integers without using the operators + and -.

 

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
 

Constraints:

-1000 <= a, b <= 1000
*/


class Solution {
public:
    int getSum(int a, int b) {
        long mask = 0xFFFFFFFF; // prevent negative value from executing left shift
        return b == 0 ? a : getSum(a ^ b, ((a & b) & mask) << 1);
    }
};

class Solution2 {
public:
    int getSum(int a, int b) {
    	// a ^ b : sum without the carry
    	// (a & b) << 1 : carry
        return b == 0 ? a : getSum(a ^ b, (unsigned int)(a & b) << 1);
    }
};