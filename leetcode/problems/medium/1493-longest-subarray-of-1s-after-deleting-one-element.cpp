/*
Longest Subarray of 1's After Deleting One Element

Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array.

Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
Example 4:

Input: nums = [1,1,0,0,1,1,1,0,1]
Output: 4
Example 5:

Input: nums = [0,0,0]
Output: 0
 

Constraints:

1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
*/

class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        // approach: 
        // count contiguous 1s before every index from the left & right side
        // find the max of the sum of l[i] & r[i] 
        int n=arr.size();
        int l[n],r[n]; 
        int one=0,res=0; 
        for (int i=0; i<n; i++){ 
            l[i]=one; 
            if (arr[i]==1) one++; 
            else one = 0; 
        } 
        one = 0; 
        for (int i=n-1; i>=0; i--) { 
            r[i] = one; 
            if (arr[i]==1) one++; 
            else one = 0; 
        } 
        for (int i=0;i<n;i++)  
            res = max(res,l[i]+r[i]);
        
        return res; 
    }
};

//     0 1 1 1 0 1 1 0 1
// l   0 0 1 2 3 0 1 2 0 
// r   3 2 1 0 2 1 0 1 0 
// --------------------------
//     3 3 3 3 5 2 2 3 1