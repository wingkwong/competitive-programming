/*
Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=0;
        int sz=nums.size();
        // loop thru the array and check if it is non-zero
        // if so, move it to position k and increase k by 1
        // 0 1 0 3 12    // k = 0
        //   ^           
        // 1 1 0 3 12    // k = 1
        //       ^
        // 1 3 0 3 12    // k = 2
        //          ^
        // 1 3 12 3 12   // k = 3
        for(int i=0;i<sz;i++) if(nums[i]!=0) nums[k++]=nums[i]; 
        // Starting from position k, replace all the number with 0 till nums.size()-1
        // 1 3 12 3 12   // k = 3
        //        ^
        // 1 3 12 0 0
        for(int i=k;i<sz;i++) nums[i]=0; 
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
