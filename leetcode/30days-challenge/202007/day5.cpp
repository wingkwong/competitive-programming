/*
Hamming Distance

Solution
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        // x:0001
        // y:0100
        // k:0101
        int k = x^y;
        int ans=0;
        while(k){
            // count 1
            ans+=k&1;
            // shift one bit to the right
            k>>=1;
        }
        return ans;
    }
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();