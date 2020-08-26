#include "solution.hpp"
using namespace std;


class Solution {
    public:
    bool solve(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++){
            if(m.count(k-nums[i])) return true;
            m[nums[i]]=i;
        }
        return false;
    }
};
