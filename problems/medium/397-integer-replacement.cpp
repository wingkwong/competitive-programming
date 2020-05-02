/*
Integer Replacement

Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1
Example 2:

Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1
*/

class Solution {
public:
    int integerReplacement(int n) {
        // for n = INT_MAX (2147483647), n+1 would cause int overflow
        if(n==INT_MAX) return integerReplacement(n-1);
        if(n==1) return 0;
        // if n is even, replace n with n/2.
        if(n%2==0) return integerReplacement(n/2)+1;
        // if n is odd, you can replace n with either n + 1 or n - 1.
        return min(integerReplacement(n-1),integerReplacement(n+1))+1;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();