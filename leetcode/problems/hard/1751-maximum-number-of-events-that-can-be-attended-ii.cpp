/*
Maximum Number of Events That Can Be Attended II
https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/

You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.

You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

Return the maximum sum of values that you can receive by attending events.

 

Example 1:



Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
Output: 7
Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
Example 2:



Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
Output: 10
Explanation: Choose event 2 for a total value of 10.
Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.
Example 3:



Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
Output: 9
Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.
 

Constraints:

1 <= k <= events.length
1 <= k * events.length <= 106
1 <= startDayi <= endDayi <= 109
1 <= valuei <= 106
*/

class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& e, int i, int k) {
        if(k == 0 || i >= e.size()) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        // to upper_bound to speed up to find the next meeting we can attend
        auto j = upper_bound(e.begin(), e.end(), e[i][1], [](int t, const vector<int>& v) {
            return v[0] > t;
        }) - e.begin();
        // either take it and try the next meeting or do not take it
        return dp[i][k] = max(e[i][2] + dfs(e, j, k - 1), dfs(e, i + 1, k));
    }
    int maxValue(vector<vector<int>>& events, int k) {
        dp = vector<vector<int>>(events.size(), vector<int>(k + 1, -1));
        sort(events.begin(), events.end());
        return dfs(events, 0, k);
    }
};