/*

*/

class Solution {
public:
    int findComplement(int num) {
        // input + output = 111..111 (all 1s)
        int k = 1;
        // 1 
        // 11 - (3) - 1*2+1
        // --------------
        // 111 - (7) - 3*2 +1
        // 1111 - (15) - 7*2 +1
        while(k<num) k = k*2+1;
        // 111 (7) 
        // 101 (5)
        // ---------
        // 010 (2)
        return k-num;
    }
};

class Solution {
public:
    int findComplement(int num) {
        // input + output = 111..111 (all 1s)
        int k = 1;
        // shift 1 & add 1
        // 1
        // 11  (10 + 1)
        // 111 (110 + 1)
        while(k<num) k = (k<<1)+1;
        // 111 (7) 
        // 101 (5)
        // ---------
        // 010 (2)

        return k^num;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();