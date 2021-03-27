/*
Valid Boomerang
https://leetcode.com/problems/valid-boomerang/

Given an array points where points[i] = [xi, yi] represents a point on the X-Y plane, return true if these points are a boomerang.

A boomerang is a set of three points that are all distinct and not in a straight line.

 

Example 1:

Input: points = [[1,1],[2,3],[3,2]]
Output: true
Example 2:

Input: points = [[1,1],[2,2],[3,3]]
Output: false
 

Constraints:

points.length == 3
points[i].length == 2
0 <= xi, yi <= 100
*/

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& p) {
    	// Triangle area given 3 points :
        // | (Ax * (By − Cy) + Bx * (Cy − Ay) + Cx * (Ay − By)) / 2 |
        return  p[0][0] * (p[1][1] - p[2][1]) + 
                p[1][0] * (p[2][1] - p[0][1]) + 
                p[2][0] * (p[0][1] - p[1][1]) != 0;
    }
};