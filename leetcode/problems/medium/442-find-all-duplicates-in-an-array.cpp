/*
Find All Duplicates in an Array

Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        // use nums as frequency array 
        // if it is visited, set it to negative 
        // if the num has been visited, then the current number occurs twice
        for(int num:nums){
            num=abs(num);
            if(nums[num-1]<0){
                ans.emplace_back(num);
            }else{
                nums[num-1]=-nums[num-1];
            }
        }
        return ans;
    }
};