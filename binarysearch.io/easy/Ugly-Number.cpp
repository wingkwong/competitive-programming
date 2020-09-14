/*
Ugly Number
https://binarysearch.io/problems/Ugly-Number

Given an integer n, return whether its prime factors only include 2, 3 or 5.

Constraints

n ≤ 2**31 -1
Example 1
Input

n = 10
Output

true
Explanation

10's prime factors are 2 and 5.

Example 2
Input

n = 14
Output

false
Explanation

14's prime factors include 7.
*/

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    bool solve(int n) {
        while(n%2==0) n/=2;
        while(n%3==0) n/=3;
        while(n%5==0) n/=5;
        return n==1;
    }
};
