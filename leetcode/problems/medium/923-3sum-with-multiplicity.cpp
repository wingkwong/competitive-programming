/*
3Sum With Multiplicity
https://leetcode.com/problems/3sum-with-multiplicity/

Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.

As the answer can be very large, return it modulo 109 + 7.

 

Example 1:

Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (arr[i], arr[j], arr[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.
Example 2:

Input: arr = [1,1,2,2,2,2], target = 5
Output: 12
Explanation: 
arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
We choose one 1 from [1,1] in 2 ways,
and two 2s from [2,2,2,2] in 6 ways.
 

Constraints:

3 <= arr.length <= 3000
0 <= arr[i] <= 100
0 <= target <= 300
*/

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long> m;
        long ans = 0;
        int M = 1e9 + 7;
        for(int x : arr) m[x]++;
        for(auto k1 : m) {
            for(auto k2: m) {
                int i = k1.first, j = k2.first, k = target - i - j;
                if(!m.count(k)) continue;
                // n choose 2 = n * (n - 1) / 2
                if(i == j && j == k) ans += m[i] * (m[i] - 1) * (m[i] - 2) / 6;
                else if(i == j && j != k) ans += m[i] * (m[i] - 1) / 2 * m[k];
                else if(i < j && j < k) ans += m[i] * m[j] * m[k];
            }
        }
        return ans % M;
    }
};