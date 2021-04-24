/*
Maximal Rectangle
https://leetcode.com/problems/maximal-rectangle/

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = []
Output: 0
Example 3:

Input: matrix = [["0"]]
Output: 0
Example 4:

Input: matrix = [["1"]]
Output: 1
Example 5:

Input: matrix = [["0","0"]]
Output: 0
 

Constraints:

rows == matrix.length
cols == matrix[i].length
0 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/

class Solution {
public:
    // 84. Largest Rectangle in Histogram
    // https://leetcode.com/problems/largest-rectangle-in-histogram/
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int mx_area = 0;
        for(int i = 0; i < heights.size(); i++) {
            if(st.empty() || heights[i] >= heights[st.top()]) {
                st.push(i);
            } else {
                int cur_height = heights[st.top()];
                st.pop();
                int cur_width = st.empty() ? i : i - 1 - st.top();
                mx_area = max(mx_area, cur_height * cur_width);
                i--;
            }
        }
        return mx_area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        if(matrix.size() == 0) return ans;
        vector<int> height(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == '0') height[j] = 0;
                else height[j]++;
            }
            ans = max(ans, largestRectangleArea(height));
        }
        return ans;
    }
};