/*
Find Minimum in Rotated Sorted Array II

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
Note:

This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        // binary search approach
        // if nums[left] > nums[mid], that means the smaller value is between mid+1 and right
        // else it is located on another side
        int l=0,r=nums.size()-1;
        while(l<r){
            int m = l+(r-l)/2;
            if(nums[m]<nums[r]) r=m;
            else if(nums[m]>nums[r]) l=m+1;
            else { // handle nums[m]==nums[r]
                if(nums[m]<nums[l]) l++;
                else r--;
            }
        }
        return nums[l];
    }
};