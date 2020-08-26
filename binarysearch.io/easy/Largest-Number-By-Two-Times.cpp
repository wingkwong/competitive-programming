#include "solution.hpp"
using namespace std;


class Solution {
    public:
    bool solve(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        return nums[0]>nums[1]*2;
    }
};
