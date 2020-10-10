/*
LeetCode - Minimum Number of Arrows to Burst Balloons

There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.

Example:

Input:
[[10,16], [2,8], [1,6], [7,12]]

Output:
2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=0;
        long t=LONG_MIN;
        if(points.size()==0) return ans;
        sort(points.begin(),points.end(),[](vector<int>& a, vector<int>& b){
            // sort by the end point
            return a[1]<b[1];
        });
        // traverse each point
        for(int i=0;i<points.size();i++){
            if(t<points[i][0]){
                // if the previous end point is less than current start point
                // that means a new non-overlapping interval is found
                // update t and add 1 to ans
                t=points[i][1];
                ans++;
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 0, minEnd = INT_MAX;
        sort(points.begin(), points.end());
        for(auto& p: points) {
            if(p[0] > minEnd) {count++; minEnd = p[1];}
            else minEnd = min(minEnd, p[1]);
        }
        return count + !points.empty();
    }
};
