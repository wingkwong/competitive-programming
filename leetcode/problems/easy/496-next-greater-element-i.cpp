/*
Next Greater Element I

You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // stack approach
        stack<int> s;
        unordered_map<int,int> m;
        for(int n:nums2){
            // if s.top() is less than n 
            // set n as the next greater for all s.top()<n cases
            while(s.size()&&s.top()<n){
                m[s.top()]=n;
                s.pop();
            }
            s.push(n);
        }
        int sz=nums1.size();
        vector<int> ans(sz,-1);
        for(int i=0;i<sz;i++){
            auto lt=m.find(nums1[i]);
            // if it can be found, the ans is lt->second
            if(lt!=m.end()){
                ans[i]=lt->second;
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // small numbers  
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            int next=0, t=-1;
            for(int j=0;j<nums2.size();j++){
                if(next){
                    if(nums2[j]>nums1[i]) {
                        t=nums2[j];
                        break;
                    }
                }
                if(nums1[i]==nums2[j]){
                    next = 1;
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};