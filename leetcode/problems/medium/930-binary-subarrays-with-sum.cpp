/*
Binary Subarrays With Sum
https://leetcode.com/problems/binary-subarrays-with-sum/

In an array A of 0s and 1s, how many non-empty subarrays have sum S?

 

Example 1:

Input: A = [1,0,1,0,1], S = 2
Output: 4
Explanation: 
The 4 subarrays are bolded below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
 

Note:

A.length <= 30000
0 <= S <= A.length
A[i] is either 0 or 1.
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n = A.size();
        vector<int> p(n + 1, 0);
        for(int i = 0; i < n; i++) p[i + 1] = p[i] + A[i];
        map<int, int> m;
        int ans = 0;
        for(int x : p) {
            ans += m[x];
            // p[j] - p[i] = S 
            m[x + S]++;
        }
        return ans;
    }
};