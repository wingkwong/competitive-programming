#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(vector<int>& nums) {
        int even=0, odd=0;
        for(int num:nums){
            if(num&1) odd++;
            else even++;
        }
        return odd*even;
    }
};
