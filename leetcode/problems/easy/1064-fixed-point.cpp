/*
Fixed Point
https://leetcode.com/problems/1064

Given an array of distinct integers arr, where arr is sorted in ascending order, return the smallest index i that satisfies arr[i] == i. If there is no such index, return -1.

 

Example 1:

Input: arr = [-10,-5,0,3,7]
Output: 3
Explanation: For the given array, arr[0] = -10, arr[1] = -5, arr[2] = 0, arr[3] = 3, thus the output is 3.
Example 2:

Input: arr = [0,2,5,8,17]
Output: 0
Explanation: arr[0] = 0, thus the output is 0.
Example 3:

Input: arr = [-10,-5,3,4,7,9]
Output: -1
Explanation: There is no such i that arr[i] == i, thus the output is -1.
 

Constraints:

1 <= arr.length < 104
-109 <= arr[i] <= 109
*/

class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        while(l < r) {
            int m = (l + r) / 2;
            if(arr[m] - m < 0) l = m + 1;
            else r = m;
        }
        return arr[l] == l ? l : -1;
    }
};

class Solution2 {
public:
    int fixedPoint(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == i) return i;
        }
        return -1;
    }
};

