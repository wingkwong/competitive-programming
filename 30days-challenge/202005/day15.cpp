/*
Maximum Sum Circular Subarray
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
Example 3:

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
Example 4:

Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
Example 5:

Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1
 

Note:

-30000 <= A[i] <= 30000
1 <= A.length <= 30000
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total_sum=0, global_max=INT_MIN, global_min=INT_MAX, local_min=0, local_max=0;
        // kadane's algorithm
        for(int a:A){
            local_max=max(a,local_max+a);
            global_max=max(global_max,local_max);
            local_min=min(a,local_min+a);
            global_min=min(global_min,local_min);
            total_sum+=a;
        }
        // case 1: max subarray is not circular
        // ______________________________
        // |    | Max subarray|          |     
        // 0 --------------------------- N-1

        // case 2: max subarray is circular
        // _____________________________
        // |    | Max su|barray|         |     
        // 0 -----------|N-1------------ 2N-1

        // which is equal to 
        // ______________________________
        // | max | Min subarray| subarray|     
        // 0 --------------------------- N-1

        // max(the max subarray sum, the total sum - the min subarray sum)

        return global_max>0?max(global_max, total_sum-global_min):global_max;
    }
};