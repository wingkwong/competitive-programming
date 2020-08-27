#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(vector<int>& nums, int k) {
        int ans=-1, cnt=0;
        for(int i=0;i<nums.size();i++){
            cnt+=nums[i];
            if(cnt<=k) ans=i;
        }
        return ans;
    }
};
