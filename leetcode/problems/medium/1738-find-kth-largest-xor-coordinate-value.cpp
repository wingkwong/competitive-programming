/*
Find Kth Largest XOR Coordinate Value
https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/

You are given a 2D matrix of size m x n, consisting of non-negative integers. You are also given an integer k.

The value of coordinate (a, b) of the matrix is the XOR of all matrix[i][j] where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).

Find the kth largest value (1-indexed) of all the coordinates of matrix.

 

Example 1:

Input: matrix = [[5,2],[1,6]], k = 1
Output: 7
Explanation: The value of coordinate (0,1) is 5 XOR 2 = 7, which is the largest value.
Example 2:

Input: matrix = [[5,2],[1,6]], k = 2
Output: 5
Explanation: The value of coordinate (0,0) is 5 = 5, which is the 2nd largest value.
Example 3:

Input: matrix = [[5,2],[1,6]], k = 3
Output: 4
Explanation: The value of coordinate (1,0) is 5 XOR 1 = 4, which is the 3rd largest value.
Example 4:

Input: matrix = [[5,2],[1,6]], k = 4
Output: 0
Explanation: The value of coordinate (1,1) is 5 XOR 2 XOR 1 XOR 6 = 0, which is the 4th largest value.
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
0 <= matrix[i][j] <= 106
1 <= k <= m * n
*/

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = (int) matrix.size(), n = (int) matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = matrix[0][0];
        vector<int> v;
        for(int i = 1; i < n; i++) {
        	// a | b | c 
        	// - >  a | a ^ b | a ^ b ^ c
            dp[0][i] = dp[0][i - 1] ^ matrix[0][i];
        }
        for(int i = 1; i < m; i++) {
        	// a 	 a
        	// f  -> a ^ f	
        	// k     a ^ f ^ k
            dp[i][0] = dp[i - 1][0] ^ matrix[i][0];
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
            	// e.g (1, 1)
            	// a ^ a ^ b ^ a ^ f ^ g
            	// = a ^ b ^ f ^ g
                dp[i][j] = dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1] ^ matrix[i][j];
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                v.push_back(dp[i][j]);
            }
        }
        sort(v.rbegin(), v.rend());
        return v[k - 1];
    }
};