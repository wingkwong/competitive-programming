/*
Sliding Window Median

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Median
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
Therefore, return the median sliding window as [1,-1,-1,3,5,6].

Note:
You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.
Answers within 10^-5 of the actual value will be accepted as correct.
*/

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> Ordered_set;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        Ordered_set s;
        vector<double> ans;
        int n = (int)nums.size();
        for(int i=0;i<k;i++) s.insert(nums[i]);
        if(k&1){
            // if k is odd, just take the middle one
            ans.push_back((double)*s.find_by_order(k/2));
            for(int i=0;i<n-k;i++){
                s.erase(s.find_by_order(s.order_of_key(nums[i])));
                s.insert(nums[i+k]);
                ans.push_back((double)*s.find_by_order(k/2));
            }
        } else {
            // if k is even, find the left element and the right element, sum them up and divide by 2
            // example: [1,2,3,4] -> (2+3)/2 -> [2.50000]
            ans.push_back(((double)*s.find_by_order((k+1)/2-1)+(double)*s.find_by_order(k/2))/2);
            for(int i=0;i<n-k;i++){
                s.erase(s.find_by_order(s.order_of_key(nums[i])));
                s.insert(nums[i+k]);
                ans.push_back(((double)*s.find_by_order((k+1)/2-1)+(double)*s.find_by_order(k/2))/2);
            }
        }
        return ans;
    }
};