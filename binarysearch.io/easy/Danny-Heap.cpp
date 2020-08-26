#include "solution.hpp"
using namespace std;


class Solution {
    public:
    bool solve(vector<int>& nums) {
        int n = (int) nums.size();
        for(int i=0;i<n;i++){
            if(2*i+1<n&&nums[i]<nums[2*i+1]) return false;
            if(2*i+2<n&&nums[i]<nums[2*i+2]) return false;
        }
        return true;
    }
};
