/*
Find Minimum in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        // binary search approach
        // if nums[left] > nums[mid], that means the smaller value is between mid+1 and right
        // else it is located on another side
        int l=0,r=nums.size()-1,m;
        while(l<r){
            m = l+(r-l)/2;
            if(nums[m]<nums[r]) r=m;
            else l=m+1;
        }
        return nums[l];
    }
};

class Solution2 {
public:
    int findMin(vector<int>& nums) {
        return *min_element(nums.begin(),nums.end());
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();