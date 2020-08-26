#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(vector<int>& nums) {
        vector<int> nums2(nums.begin(), nums.end());
        sort(nums2.begin(), nums2.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==nums2[i]){
                ans++;
            }
        }
        return ans;
    }
};
