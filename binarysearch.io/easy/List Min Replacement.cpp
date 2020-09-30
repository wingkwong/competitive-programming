/*
List Min Replacement
https://binarysearch.com/problems/List-Min-Replacement

Given a list of integers nums, replace every nums[i] with the smallest integer left of i. Replace nums[0] with 0.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input

nums = [10, 5, 7, 9]
Output

[0, 10, 5, 5]
Explanation

nums[0] = 0 by definition
nums[1] = min(10)
nums[2] = min(5, 10)
nums[3] = min(7, 5, 10)
*/

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<int> solve(vector<int>& nums) {
        if(nums.size()==0) return {};
        int mi=nums[0], tmp;
        for(int i=1;i<=nums.size();i++){
            tmp=nums[i-1];
            nums[i-1]=mi;
            mi=min(mi,tmp);
        }
        nums[0]=0;
        return nums;
    }
};

class Solution2 {
    public:
    vector<int> solve(vector<int>& nums) {
        vector<int> ans;
        if(nums.size()==0) return ans;
        int mi = 0;
        for(int i=0;i<nums.size();i++){
            if(i==0) {
                ans.push_back(mi);
                mi = nums[i];
            }
            else {
                ans.push_back(mi);
                mi = min(mi, nums[i]);
            }
        }
        return ans;
    }
};

