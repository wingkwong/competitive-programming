/*
Largest Rectangle in Histogram
https://leetcode.com/problems/largest-rectangle-in-histogram/

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

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


class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), area = 0, h, l;
		stack<int> indexes;
		for (int i = 0; i <= n; i++) {
			while (i == n || (!indexes.empty() && heights[indexes.top()] > heights[i])) {
				if (i == n && indexes.empty()) h = 0, i++;
				else h = heights[indexes.top()], indexes.pop();			
				l = indexes.empty() ? -1 : indexes.top();
				area = max(area, h * (i - l - 1));
			}
			indexes.push(i);
		}
		return area;
    }
};