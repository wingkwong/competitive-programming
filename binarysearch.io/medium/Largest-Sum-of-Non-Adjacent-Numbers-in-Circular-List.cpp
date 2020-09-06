/*
Largest Sum of Non-Adjacent Numbers in Circular List
https://binarysearch.io/problems/Largest-Sum-of-Non-Adjacent-Numbers-in-Circular-List

You are given a list of integers nums representing a circular list (the first and the last elements are adjacent). Return the largest sum of non-adjacent numbers.

Constraints

n ≤ 100,000 where n is the length of nums.
Example 1
Input

nums = [9, 2, 3, 5]
Output

12
Explanation

We can take 9 and 3. Note that we can't take 9 and 5 since they are adjacent.
*/

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
        if(n<2) return 0;
        return max(solve(nums,0,n-2), solve(nums,1,n-1));
    }
};