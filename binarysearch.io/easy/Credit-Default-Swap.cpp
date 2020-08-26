#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<int> solve(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i+=4){
            if(i+2<n) swap(nums[i], nums[i+2]);
            if(i+3<n) swap(nums[i+1], nums[i+3]);
        }
        return nums;
    }
};
