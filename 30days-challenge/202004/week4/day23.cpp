/*
Bitwise AND of Numbers Range

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4


Example 2:

Input: [0,1]
Output: 0
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // reduce n by removing the rightest 1 bit until n<=m
        while(m<n) n = n&(n-1);
        return n;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

// 0101 - 5
// 0110 - 6
// 0111 - 7
// ----
// 0100
