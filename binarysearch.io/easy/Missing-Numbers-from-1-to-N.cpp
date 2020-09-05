/*
Missing Numbers from 1 to N
https://binarysearch.io/problems/Missing-Numbers-from-1-to-N

You are given a list of integers nums of length n where all numbers in the list are from [1, n] and some elements appear twice while others only once. Return all the numbers from [1, n] that are not in the list, sorted in ascending order.

Can you do it in \mathcal{O}(n)O(n) time, modify nums in-place and use \mathcal{O}(1)O(1) additional space?

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input

nums = [3, 3, 1, 1, 5, 5]
Output

[2, 4, 6]
Explanation

The numbers [2, 4, 6] are missing from [1, 6]
*/

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<int> solve(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int num = nums[i];
            while(num>0&&num<=n&&nums[num-1]!=num){
                swap(nums[num-1], num);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) ans.push_back(i+1);
        }
        return ans;
    }
};
