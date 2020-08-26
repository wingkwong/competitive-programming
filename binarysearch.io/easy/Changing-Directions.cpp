#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(vector<int>& nums) {
        int ans=0, n = nums.size();
        if(n==0) return ans;
        for(int i=0;i<n-2;i++){
            int f=nums[i], s=nums[i+1], t=nums[i+2];
            if (
                f<s&&s>t ||
                f>s&&s<t
            )  ans++;
        }
        return ans;
    }
};
