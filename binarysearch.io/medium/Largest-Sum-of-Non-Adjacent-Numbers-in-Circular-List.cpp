#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(vector<int>& nums, int start, int end){
        int prev=0, cur=0;
        for(int i=start; i<=end; i++){
            int tmp = max(prev+nums[i], cur);
            prev = cur;
            cur = tmp;
        }
        return cur;
    }
    int solve(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n?nums[0]:0;
        return max(solve(nums,0,n-2), solve(nums,1,n-1));
    }
};