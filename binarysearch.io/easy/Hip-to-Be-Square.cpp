#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<int> solve(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]*=nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};
