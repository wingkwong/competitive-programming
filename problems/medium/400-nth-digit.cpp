/*
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/

class Solution {
public:
    int findNthDigit(int n) {
        // 1~9: 1*9=9 in total
        // 10~99: 2*90=180 in total
        // 100~999: 3*900=2700 in total

        // Example: n=250
        long digits=1;
        int base=9;
        while(n-base*digits>0) {
            n -= base*digits;
            base *= 10;
            digits++;
        }
        // n=61 (250-9-180)
        // digits=3
        // We need to get the 61th number starting from 100
        // idx=0
        int idx = (n-1)%digits;
        // offset=20
        int offset = (n-1)/digits;
        // k=100 (10^(3-1))
        long k = pow(10,digits-1);
        // 100+20 -> 120 -> 1
        return to_string(k+offset)[idx] - '0';
    }
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();