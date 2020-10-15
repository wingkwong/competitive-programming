/*
Concatenated Sums
https://binarysearch.com/problems/Concatenated-Sums

You are given a list of non-negative integers nums. Return the sum of every concatenation of every pair of numbers in nums. Note that pairs (i, j) and (j, i) are considered different.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input

nums = [10, 2]
Output

1344
Explanation

We have the following concatenations:

nums[0] + nums[0] = 1010
nums[0] + nums[1] = 102
nums[1] + nums[0] = 210
nums[1] + nums[1] = 22
And its sum is 1344
*/

#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int countBits(int n) {
        if(n == 0) return 1;
        int cnt = 0;
        while(n) {
            cnt++;
            n /= 10;
        }
        return cnt;
     }
     
    int solve(vector<int>& nums) {
        // nums = [a, b, c]
        // for x in nums
        // ans += x * 10 ^ countBits(x) + a
        // ans += x * 10 ^ countBits(x) + b
        // ans += x * 10 ^ countBits(x) + c
        // let  sum = a + b + c
        //      p   = 10 ^ countBits(a) + 10 ^ countBits(b) + 10 ^ countBits(c)
        // ans = ( a * p + sum ) + ( b * p + sum ) + ( c * p + sum )
        int ans = 0, sum = 0, p = 0;
        for(int n : nums) {
            sum += n;
            p += pow(10, countBits(n));
        }
        for(int n : nums) {
            ans += n * p + sum;
        }
        return ans;
    }
};