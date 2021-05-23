/*
Maximum Distance in Arrays
https://leetcode.com/problems/maximum-distance-in-arrays/

You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.

 

Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Example 2:

Input: arrays = [[1],[1]]
Output: 0
Example 3:

Input: arrays = [[1],[2]]
Output: 1
Example 4:

Input: arrays = [[1,4],[0,5]]
Output: 4
 

Constraints:

m == arrays.length
2 <= m <= 105
1 <= arrays[i].length <= 500
-104 <= arrays[i][j] <= 104
arrays[i] is sorted in ascending order.
There will be at most 105 integers in all the arrays.
*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0, mi = arrays[0].front(), mx = arrays[0].back(), n =  arrays.size();
        for(int i = 1; i < n; i++) {
            ans = max(ans, max(arrays[i].back() - mi, mx - arrays[i].front()));
            mi = min(mi, arrays[i].front());
            mx = max(mx, arrays[i].back());
        }
        return ans;
    }
};