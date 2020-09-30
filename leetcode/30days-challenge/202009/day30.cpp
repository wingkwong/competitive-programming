/*
First Missing Positive

Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Follow up:

Your algorithm should run in O(n) time and uses constant extra space.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // putting each number in its right place
        int n = nums.size();
        for(int i=0;i<n;i++){
            int num = nums[i];
            while(num>0&&num<=n&&nums[num-1]!=num){
                swap(nums[num-1], num);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};