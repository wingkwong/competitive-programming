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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
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