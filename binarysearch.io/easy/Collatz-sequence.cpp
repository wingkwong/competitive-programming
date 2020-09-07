/*
Collatz-sequence
https://binarysearch.io/problems/Collatz-sequence

Given a positve integer n, find the length of its Collatz sequence. Collatz sequence is generated sequentially where

n = n / 2 if n is even
n = 3 * n + 1 if n is odd
And the sequence ends if n = 1
Example 1
Input

n = 11
Output

15
Explanation

The Collatz sequence is: [11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1] and its length is 15.
*/

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(int n) {
        int ans=1;
        while(n>1){
            if(n&1) n=3*n+1;
            else n>>=1;
            ans++;
        }
        return ans;
    }
};
