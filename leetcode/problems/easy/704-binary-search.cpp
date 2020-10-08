/*
Binary Search

Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.


Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Note:

You may assume that all elements in nums are unique.
n will be in the range [1, 10000].
The value of each element in nums will be in the range [-9999, 9999].

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=(int) nums.size(), l=-1, r=n;
        while(r>l+1){
            int m=l+(r-l)/2;
            if(target<=nums[m]) r=m;
            else l=m;
        }
        return r<n&&nums[r]==target?r:-1;
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};