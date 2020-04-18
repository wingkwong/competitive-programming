/*
Self Dividing Numbers

A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

Example 1:
Input: 
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
Note:

The boundaries of each input argument are 1 <= left <= right <= 10000.
*/

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;i++){
            if(isSelfDividing(i)) ans.push_back(i);
        }
        return ans;
    }
private: 
    bool isSelfDividing(int i){
        if(i<10) return true;
        int t=i;
        while(i){
            int d=i%10;
            // !d: a self-dividing number is not allowed to contain the digit zero.
            // t%d: a self-dividing number is a number that is divisible by every digit 
            if(!d||t%d) return false;
            i/=10;
        }
        return true;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();