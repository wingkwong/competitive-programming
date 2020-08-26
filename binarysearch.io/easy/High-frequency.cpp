#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans=0;
        for(int num:nums){
            m[num]++;
            ans=max(ans,m[num]);
        }
        return ans;
    }
};
