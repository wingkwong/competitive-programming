/*
Triangle

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=(int)triangle.size();
        // starting from the second last row
        // e.g. [6,5,7]
        for(int i=n-2;i>=0;i--){
            // traverse each item
            for(int j=0;j<(int)triangle[i].size();j++){
                // add itself to the min of below 2 numbers
                // e.g j=0: 6 + min(4,1) = 7 
                //     j=1: 5 + min(1,8) = 6 
                //     j=2: 7 + min(8,3) = 10
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        // at the end, the value in the top row is the min sum
        return triangle[0][0];
    }
};