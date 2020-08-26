/*
Non-overlapping Intervals

Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Example 1:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:

Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:

Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Note:

You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // similar to 56 - Merge Intervals
        int ans=0;
        if(intervals.size()==0) return ans;
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[0]<b[0];
        });
        for(int i=1,j=0;i<intervals.size();i++){
            // check if they are overlapping
            if(intervals[i][0]<intervals[j][1]){
                // if so, add 1 to ans
                ans++;
                // if the end time of intervals[j] is greater than that of intervals[i]
                // intervals[j] should be removed 
                // so we update j 
                if(intervals[j][1]>intervals[i][1]){
                    // [[1,100],[11,22],[1,11],[2,12]]
                    j=i;
                }
            } else{
                // update j for the next check
                j=i;
            }
        }
        return ans;
    }
};