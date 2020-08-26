/*
Majority Element II

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // simply solved by Boyer-Moore Voting Algorithm
        // There can be at most one majority element which is more than ⌊n/2⌋ times.
        // There can be at most two majority elements which are more than ⌊n/3⌋ times.
        // There can be at most three majority elements which are more than ⌊n/4⌋ times.
        vector<int> ans;
        int sz = (int) nums.size();
        if(sz==0) return ans;
        int c1=0,c2=0,cnt1=0,cnt2=0;
        for(int n:nums){
            if(n==c1) cnt1++;
            else if(n==c2) cnt2++;
            else if(cnt1==0) c1=n, cnt1=1;
            else if(cnt2==0) c2=n, cnt2=1;
            else --cnt1, --cnt2;
        }
        cnt1=0, cnt2=0;
        for(int n:nums){
            if(n==c1) cnt1++;
            else if(n==c2) cnt2++;
        }      
        if(cnt1>sz/3) ans.push_back(c1);
        if(cnt2>sz/3) ans.push_back(c2);
        
        return ans;
    }
};