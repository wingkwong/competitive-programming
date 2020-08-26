/*
Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

Given an array of integers nums and an integer limit, return the size of the longest continuous subarray such that the absolute difference between any two elements is less than or equal to limit.

In case there is no subarray satisfying the given condition return 0.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= limit <= 10^9
*/

// AC - Sliding Windows with Tree Map
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = (int)nums.size();
        int i=0,j=0;
        multiset<int> ms;
        for(;i<n;i++){
            ms.insert(nums[i]);
            while(*ms.rbegin()-*ms.begin()>limit) ms.erase(ms.find(nums[j++]));
            // j=0
            // 8 2 4 7

            // 8
            // 2 8 - 6 > 4
            // erase 8 -> j=1

            // 2 4 - 2
            // 2 4 7 - 5 > 4
            // erase 2 -> j=2

            // i=4 j=2 
            // ans = i - j = 4 -2 = 2
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};

// Time Limit Exceed
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = (int)nums.size();
        int ans=INT_MIN;
        int minJ,maxI;
        for(int i=0;i<n;i++){
            maxI=nums[i];
            minJ=nums[i];
            for(int j=i;j<n;j++){
                maxI=max(maxI,nums[j]);
                minJ=min(minJ,nums[j]);
                // cout << maxI << " " << minJ << endl;
                if(abs(maxI-minJ)<=limit){
                    ans=max(ans,(j-i+1));
                }
            }
        }
        return ans;
    }
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

