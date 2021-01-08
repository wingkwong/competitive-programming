/*
Gray Code
https://leetcode.com/problems/gray-code/

The gray code is a binary numeral system where two successive values differ in only one bit.

Given an integer n representing the total number of bits in the code, return any sequence of gray code.

A gray code sequence must begin with 0.

 

Example 1:

Input: n = 2
Output: [0,1,3,2]
Explanation:
00 - 0
01 - 1
11 - 3
10 - 2
[0,2,3,1] is also a valid gray code sequence.
00 - 0
10 - 2
11 - 3
01 - 1
Example 2:

Input: n = 1
Output: [0,1]
 

Constraints:

0 <= n <= 15
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for(int i = 0; i < 1 << n; i++) {
            bitset<32> b(i ^ (i >> 1));
            ans.push_back(b.to_ulong());
        }
        return ans;
    }
};