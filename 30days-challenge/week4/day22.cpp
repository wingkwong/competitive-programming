/*
Subarray Sum Equals K

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0,sum=0;
        // use map to store cumulative sum 
        map<int,int> m;
        // (0,1)
        m[0]++;
        for(int n:nums){
            sum+=n;
            // we don't need to check if it exists or not
            // if the key is not exist, the value is still 0
            cnt+=m[sum-k];
            m[sum]++;
        }
        return cnt;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

// k = 7
// 3 4 7 2 -3 1 4 2 