#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<int> solve(vector<int>& nums) {
        if(nums.size()==0) return {};
        int mi=nums[0], tmp;
        for(int i=1;i<=nums.size();i++){
            tmp=nums[i];
            nums[i]=mi;
            mi=min(mi,tmp);
        }
        nums[0]=0;
        return nums;
    }
};
