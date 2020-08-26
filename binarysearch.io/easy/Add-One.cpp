#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<int> solve(vector<int>& nums) {
        int n=(int)nums.size(), c=1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]!=9){
                nums[i]+=1;
                return nums;
            }
            if(i==0&&nums[i]==9) {
                nums[i]=0;
                nums.insert(nums.begin(),1);
            } else {
                nums[i]=0;
            }
        }
        return nums;
    }
};
