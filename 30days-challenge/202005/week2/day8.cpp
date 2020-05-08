/*
Check If It Is a Straight Line

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

Example 1:

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 
Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = (int)coordinates.size();
        if(n==2) return true;
        for(int i=2;i<n;i++){
            // slope of points (x1,y1) and (x2,y2) is (y2-y1)/(x2-x1)
            // slope of points (x2,y2) and (x3,y3) is (y3-y2)/(x3-x2)
            // if these points are on the same line, (y2-y1)/(x2-x1) = (y3-y2)/(x3-x2)
            // to avoid division by 0, change the form to 
            // (y2-y1)*(x3-x2) = (y3-y2)*(x2-x1)
            int y2y1 = coordinates[i][1]-coordinates[i-1][1];
            int y3y2 = coordinates[i-1][1]-coordinates[i-2][1];
            int x2x1 = coordinates[i][0]-coordinates[i-1][0];
            int x3x2 = coordinates[i-1][0]-coordinates[i-2][0];
            if(y2y1*x3x2!=y3y2*x2x1) return false;
        }
        return true;
    }
};

// [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
// [[-3,-2],[-1,-2],[2,-2],[-2,-2],[0,-2]]
// [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
// [[-4,-3],[1,0],[3,-1],[0,-1],[-5,2]]