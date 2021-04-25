/*
Maximum Building Height
https://leetcode.com/problems/maximum-building-height/

You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1 to n.

However, there are city restrictions on the heights of the new buildings:

The height of each building must be a non-negative integer.
The height of the first building must be 0.
The height difference between any two adjacent buildings cannot exceed 1.
Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less than or equal to maxHeighti.

It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.

Return the maximum possible height of the tallest building.

 

Example 1:


Input: n = 5, restrictions = [[2,1],[4,1]]
Output: 2
Explanation: The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,1,2], and the tallest building has a height of 2.
Example 2:


Input: n = 6, restrictions = []
Output: 5
Explanation: The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,3,4,5], and the tallest building has a height of 5.
Example 3:


Input: n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
Output: 5
Explanation: The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,3,3,4,4,5,4,3], and the tallest building has a height of 5.
 

Constraints:

2 <= n <= 109
0 <= restrictions.length <= min(n - 1, 105)
2 <= idi <= n
idi is unique.
0 <= maxHeighti <= 109
*/

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& r) {
        r.push_back({1, 0});
        r.push_back({n, n - 1});
        sort(r.begin(), r.end());
        int m = r.size();
        for(int i = 1; i < m; i++) r[i][1] = min(r[i][1], r[i - 1][1] + r[i][0] - r[i - 1][0]);
        for(int i = m - 2; i >= 0; i--) r[i][1] = min(r[i][1], r[i + 1][1] + r[i + 1][0] - r[i][0]);
        int ans = 0;
        for(int k = 1; k < m; k++) {
            int i = r[k - 1][0], j = r[k][0];
            int h1 = r[k - 1][1], h2 = r[k][1];
            ans = max(ans, max(h1, h2) + (j - i - abs(h1 - h2)) / 2);
        }
        return ans;
    }
};