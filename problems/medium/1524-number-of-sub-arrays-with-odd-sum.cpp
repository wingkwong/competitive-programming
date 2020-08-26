/*
Number of Sub-arrays With Odd Sum

Given an array of integers arr. Return the number of sub-arrays with odd sum.

As the answer may grow large, the answer must be computed modulo 10^9 + 7.

 

Example 1:

Input: arr = [1,3,5]
Output: 4
Explanation: All sub-arrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.
Example 2:

Input: arr = [2,4,6]
Output: 0
Explanation: All sub-arrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.
Example 3:

Input: arr = [1,2,3,4,5,6,7]
Output: 16
Example 4:

Input: arr = [100,100,99,99]
Output: 4
Example 5:

Input: arr = [7]
Output: 1
 

Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 100
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // odd+odd=even
        // odd+even=odd
        // even+even=even
        // v[0]: even prefix sum
        // v[1]: odd prefix sum
        int cur=0, ans=0, v[2]={1,0}, mod=1e9+7;
        for(auto a:arr){
            cur^=a&1;
            // if current prefix sum is even, add number of the odd prefix sum
            // else add the number of even prefix sum
            ans=(ans+v[1-cur])%mod;
            // increase count by 1
            v[cur]++;
        }
        return ans;
    }
};

// TLE ...
// class Solution {
// public:
//     int numOfSubarrays(vector<int>& arr) {
//         int n = (int) arr.size();
//         int ans=0;
//         int mod = 1e9+7;
//         for(int i=0;i<n;i++){
//           for(int j=i, sum=0;j<n;j++){
//               sum+=arr[j];
//               if(sum&1) ans++;
//               ans%=mod;
//           }
//         }
//         return ans;
//     }
// };