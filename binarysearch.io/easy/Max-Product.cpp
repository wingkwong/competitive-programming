#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        return max(nums[0]*nums[1], nums[nums.size()-1]*nums[nums.size()-2]);
    }
};
