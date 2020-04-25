/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> us;
        for(int n:nums) us.insert(n);
        int sz=nums.size();
        for(int i=1;i<=sz;i++) {
            if(us.find(i)==us.end()) ans.push_back(i);
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int t;
        vector<int> ans;
        // make the index to a negative
        for(int num:nums){
           t=abs(num);
           if(nums[t-1]>0) nums[t-1] *= -1;
        }        
        // the missing index stays positive
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) ans.push_back(i+1);
        }
        return ans;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();