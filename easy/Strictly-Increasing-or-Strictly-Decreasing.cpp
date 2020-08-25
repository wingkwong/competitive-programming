#include "solution.hpp"
using namespace std;


class Solution {
    public:
    bool solve(vector<int>& nums) {
        int ok1=1,ok2=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]) {
                ok1=0;
                break;
            }
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=nums[i-1]) {
                ok2=0;
                break;
            }
        }
        
        return ok1||ok2;
    }
};
