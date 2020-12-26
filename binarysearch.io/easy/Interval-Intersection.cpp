/*
Interval Intersection
https://binarysearch.com/problems/Interval-Intersection

Given a two-dimensional integer list intervals of the form [start, end] representing intervals (inclusive), return their intersection, that is, the interval that lies within all of the given intervals.

You can assume that the intersection will be non-empty.

Constraints

1 ≤ n ≤ 100,000 where n is the length of intervals
Example 1
Input
intervals = [
    [1, 100],
    [10, 50],
    [15, 65]
]
Output
[15, 50]
Explanation
Consider the ranges [1, 100], [10, 50], [15, 65] on a line. The range [15, 50] is the only interval that is included by all of them.
*/


vector<int> solve(vector<vector<int>>& intervals) {
    int l = intervals[0][0], r = intervals[0][1];
    for(int i = 1; i < intervals.size(); i++) {
        l = max(l, intervals[i][0]);
        r = min(r, intervals[i][1]);
    }
    return vector<int>{l, r};
}