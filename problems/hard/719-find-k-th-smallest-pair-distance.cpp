/*
Find K-th Smallest Pair Distance

Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

Example 1:
Input:
nums = [1,3,1]
k = 1
Output: 0 
Explanation:
Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Note:
2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.
*/

class Solution {
public:
    // if we sort the input array in ascending order
    // this problem can actually be rephrased as finding the kth smallest element in a sorted matrix
    // see 378 - Kth Smallest Element in a Sorted Matrix
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sz=(int)nums.size();
        // any pair distance must lie in the range [0,d] where d = max - min (in nums)
        // search space: [0,d]
        int l=0,r=nums[sz-1]-nums[0],m;
        while(l<r){
            m=l+(r-l)/2;
            int cnt=0;
            // binary search + sliding window
            for(int ll=0,rr=0;rr<sz;rr++){
                // (ll,rr) where ll < rr
                while(nums[rr]-nums[ll]>m) ll++;
                cnt+=rr-ll;
            }
            
            // Alternative
            // Note that each pair distance d_ij is characterized by a pair of indices (i, j) with i < j, that is d_ij = nums[j] - nums[i]. 
            // If we keep the first index i fixed, then d_ij <= num is equivalent to nums[j] <= nums[i] + num. 
            // This suggests that at least we can do a binary search to find the smallest index j such that nums[j] > nums[i] + num for each index i, 
            // then the count from index i will be j - i - 1, and in total we have an O(nlogn) verification algorithm.

            // for(int i=0,j=0;i<sz;i++){
            //     while(j<sz&&nums[j]<=m+nums[i]) j++;
            //     cnt += j-(i+1); // i is fixed, j starts in i+1
            // }
            if(cnt>=k) r=m;
            else l=m+1;
        }
        return l;
    }
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();