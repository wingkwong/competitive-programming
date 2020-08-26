#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<int> solve(vector<int>& nums, int k) {
        k=(k%14==0)?14:k%14;
        for(int i=0;i<k;i++){
            vector<int> tmp(8,0);
            for(int j=1;j<7;j++){
                tmp[j]=(nums[j-1]==nums[j+1])?1:0;
            }
            nums=tmp;
        }
        return nums;
    }
};
