/*
Ugly Number

Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example 1:

Input: 6
Output: true
Explanation: 6 = 2 × 3
Example 2:

Input: 8
Output: true
Explanation: 8 = 2 × 2 × 2
Example 3:

Input: 14
Output: false 
Explanation: 14 is not ugly since it includes another prime factor 7.
Note:

1 is typically treated as an ugly number.
Input is within the 32-bit signed integer range: [−231,  231 − 1].
*/

class Solution {
public:
    bool isUgly(int num) {
        while(num>1){
            // check if it can be divided by 2 
            if(num%2==0) num/=2;
            // check if it can be divided by 3 
            else if(num%3==0) num/=3;
            // check if it can be divided by 5
            else if(num%5==0) num/=5;
            // if it cannot be divided by 2,3 or 5. return false 
            else return false;
        }
        // at the end num should be 1 if it can be divided by 2,3 or 5
        return num==1;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();