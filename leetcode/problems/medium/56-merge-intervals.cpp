/*
Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        // if no interval, return empty vector<vector<int>>{}
        if(intervals.size()==0) return ans;
        // sort the interval by start time
        sort(intervals.begin(),intervals.end(),[](vector<int>& a, vector<int>&b){
            return a[0]<b[0];
        });
        // put the first ans
        ans.push_back(intervals[0]);
        // traverse the rest of them
        for(int i=1;i<intervals.size();i++){
            if(ans.back()[1]<intervals[i][0]){
                // if the current end time is less than the start time of the next one
                // i.e. not overlap 
                // e.g. [[1,2],[4,5]]
                // then push back intervals[i]
                ans.push_back(intervals[i]);
            } else {
                // if it is overlapping 
                // e.g. [[1,3],[2,6]]
                // since [1,3] is already in ans
                // modify the end time in the last element of ans
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};