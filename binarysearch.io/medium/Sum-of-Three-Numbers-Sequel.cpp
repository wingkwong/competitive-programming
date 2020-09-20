/*
Sum of Three Numbers Sequel
https://binarysearch.com/problems/Sum-of-Three-Numbers-Sequel

Given a list of integers nums and an integer k, find three distinct entries in nums, a, b, c, such that abs(a + b + c - k) is minimized and return the absolute difference.

Constraints

n ≤ 1,000 where n is length of nums.
Example 1
Input

nums = [2, 4, 25, 7]
k = 15
Output

2
Explanation

Taking [2, 4, 7] will get us closest to 15 and the absolute difference is abs(13 - 15) = 2.
*/

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(vector<int>& nums, int k) {
        // 3 sum approach
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans=INT_MAX;
        for(int i=0;i<n;i++){
            int l=i+1, r=n-1;
            while(l<r){
                if(abs(nums[i]+nums[l]+nums[r]-k)<ans){
                    ans=abs(nums[i]+nums[l]+nums[r]-k);
                }else if(nums[i]+nums[l]+nums[r]>k) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};
