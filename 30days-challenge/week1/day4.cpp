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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int k=0;
        int sz=nums.size();
        for(int i=0;i<sz;i++) if(nums[i]!=0) nums[k++]=nums[i]; 
        for(int i=k;i<sz;i++) nums[i]=0; 
    }
};