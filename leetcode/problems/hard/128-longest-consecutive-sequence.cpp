/*
Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int sz=(int)nums.size();
        if(!sz) return 0;
        int ans=1,cnt=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<sz;i++){
            // since the array is sorted, the diff between nums[i] and nums[i-1] must be 1
            if(nums[i]==nums[i-1]+1){
                cnt++;
                ans=max(ans,cnt);
            }
            // if they are same, skip it
            else if(nums[i]==nums[i-1]) continue;
            else{
                // reset counter
                cnt=1;
                if(i+ans>sz) break;
            }
        }
        return ans;
    }
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();