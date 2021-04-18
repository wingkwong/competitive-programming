/*
Power of Four

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
Follow up: Could you solve it without loops/recursion?
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        return __builtin_popcount(n) == 1 && __builtin_ctz(n) % 2 == 0;
    }
};

class Solution2 {
public:
    bool isPowerOfFour(int num) {
        // 4: 100
        // 16: 10000
        // obversation: 
        // count of 1s is 1 and the number of trailing zeros is even
        return __builtin_popcount(num)==1 && // only 1 bit is set
              (__builtin_ctz(num)&1)==0;    // with even trailing zeros 
    }
};